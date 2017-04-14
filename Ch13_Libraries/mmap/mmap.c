#include "../../Ch07_InessentialCSyntax/strtod/stopif.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

#define Mapmalloc(number, type, filename, fd)                                  \
    load_mmap((filename), &(fd), (number) * sizeof(type), 'Y')

#define Mapload(number, type, filename, fd)                                    \
    load_mmap((filename), &(fd), (number) * sizeof(type), 'n')

#define Mapfree(number, type, fd, pointer)                                     \
    releasemmap((pointer), (number) * sizeof(type), (fd))

void* load_mmap(const char* filename, int* fd, size_t size, char make_room) {
    *fd = open(filename, make_room == 'Y' ? O_RDWR | O_CREAT | O_TRUNC : O_RDWR,
               (mode_t)0600);
    Stopif(*fd == -1, return NULL, "Error opening file");
    //
    // Stretch the file size to the size of the (mmapped).
    if (make_room == 'Y') {
        int result = lseek(*fd, size - 1, SEEK_SET);
        Stopif(result == -1, close(*fd);
               return NULL, "Error stretching file with lseek");
        result = write(*fd, "", 1);
        Stopif(result != 1, close(*fd);
               return NULL, "Error writing last byte of the file");
    }

    void* map = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, *fd, 0);
    Stopif(map == MAP_FAILED, return NULL, "Error mmapping the file");
    return map;
}

int releasemmap(void* map, size_t size, int fd) {
    Stopif(munmap(map, size) == -1, return -1, "Error un-mmapping the file");
    close(fd);
    return 0;
}

int main(int argc, char* arvg[]) {
    int fd;
    long int N = 1e5 + 6;
    int* map = Mapmalloc(N, int, "mmapped.bin", fd);

    for (long int i = 0; i < N; ++i) {
        map[i] = i;
    }

    Mapfree(N, int, fd, map);

    // Now reopen and do some counting.
    int* readme = Mapload(N, int, "mmapped.bin", fd);

    long long int oddsum = 0;
    for (long int i = 0; i < N; ++i) {
        if (readme[i] % 2) {
            oddsum += i;
        }
    }
    printf("The sum of odd numbers up to %li: %lli\n", N, oddsum);

    Mapfree(N, int, fd, readme);
}
