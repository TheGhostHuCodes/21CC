void set_element(int* a, const int* b) { a[0] = 3; }

int main() {
    int a[10] = {};
    const int* b = a;
    set_element(a, b);
}
