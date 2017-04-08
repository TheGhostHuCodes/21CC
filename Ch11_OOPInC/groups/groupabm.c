#include "groups.h"

int pop = 2000;
int periods = 200;
int dimension = 2;

typedef struct {
    gsl_vector* position;
    group_s* group;
} person_s;

person_s person_setup(gsl_rng* r) {
    gsl_vector* posn = gsl_vector_alloc(dimension);
    for (int i = 0; i < dimension; ++i) {
        gsl_vector_set(posn, i, 2 * gsl_rng_uniform(r) - 1);
    }
    return (person_s){.position = posn};
}

void check_membership(person_s* p, gsl_rng* r, double mass_benefit,
                      double new_group_odds) {
    group_exit(p->group, p->position);
    p->group = (gsl_rng_uniform(r) < new_group_odds)
                   ? group_new(p->position)
                   : group_join(group_closest(p->position, mass_benefit),
                                p->position);
}

void init(person_s* people, int pop, gsl_rng* r) {
    for (int i = 0; i < pop; ++i) {
        people[i] = person_setup(r);
    }
    for (int i = 0; i < 10; ++i) {
        people[i].group = group_new(people[i].position);
    }
    for (int i = 10; i < pop; ++i) {
        people[i].group = group_join(people[i % 10].group, people[i].position);
    }
}

int main() {
    double new_group_odds = (float)1 / pop;
    double mass_benefit = 0.7 / pop;
    gsl_rng* r = apop_rng_alloc(1234);

    person_s people[pop];
    init(people, pop, r);

    printf("unset key; set xrange[-1:1]\nset yrange[-1:1]\n");
    for (int t = 0; t < periods; ++t) {
        for (int i = 0; i < pop; ++i) {
            check_membership(&people[i], r, mass_benefit, new_group_odds);
        }
        print_groups();
    }
}
