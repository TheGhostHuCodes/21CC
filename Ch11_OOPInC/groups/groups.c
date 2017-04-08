#include "groups.h"

GList* group_list;

group_s* group_new(gsl_vector* position) {
    static int id = 0;
    group_s* out = malloc(sizeof(group_s));
    *out = (group_s){
        .position = apop_vector_copy(position), .id = id++, .size = 1};
    group_list = g_list_append(group_list, out);
    return out;
}

group_s* group_join(group_s* joinme, gsl_vector* position) {
    int n = ++joinme->size;
    for (int i = 0; i < joinme->position->size; ++i) {
        joinme->position->data[i] *= (n - (float)1) / n;
        joinme->position->data[i] += position->data[i] / n;
    }
    return joinme;
}

void group_exit(group_s* leaveme, gsl_vector* position) {
    int n = leaveme->size--;
    for (int i = 0; i < leaveme->position->size; ++i) {
        leaveme->position->data[i] -= position->data[i] / n;
        leaveme->position->data[i] *= n / (n - (float)1);
    }
    if (leaveme->size == 0) {
        gsl_vector_free(leaveme->position);
        group_list = g_list_remove(group_list, leaveme);
        free(leaveme);
    }
}

group_s* group_closest(gsl_vector* position, double mass_benefit) {
    group_s* fave = NULL;
    double smallest_dist = GSL_POSINF;
    for (GList* gl = group_list; gl != NULL; gl = gl->next) {
        group_s* g = gl->data;
        double dist = apop_vector_distance(g->position, position, .metric = 'L',
                                           .norm = 3)
                      - mass_benefit * g->size;
        if (dist < smallest_dist) {
            smallest_dist = dist;
            fave = g;
        }
    }
    return fave;
}

void print_groups() {
    printf("plot '-' with points pointtype 6\n");
    for (GList* gl = group_list; gl != NULL; gl = gl->next) {
        apop_vector_print(((group_s*)gl->data)->position);
    }
    printf("e\n");
}
