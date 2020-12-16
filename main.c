#include <stdio.h>
#include "vector.h"

int main(int argc, char const *argv[])
{
        w = calloc(4, sizeof(double));
        double* a = malloc(4 * sizeof(double));
        a[0] = 1.0;
        a[1] = 0.0;
        a[2] = 0.0;
        a[3] = 1.0;

        double* b = malloc(4 * sizeof(double));
        b[0] = 2.0;
        b[1] = 1.0;
        b[2] = 0.0;
        b[3] = 0.0;

        vector_t* v = new_vector(4, a); // v = [1, 0, 0, 1]
        vector_t* u = new_vector(4, b); // v = [2, 1, 0, 0]

        free(a);
        free(b);

        double s = 2.0;

        vector_scalar_sub(v, u, s);

        // [1, 0, 0, 1] - 2 * [2, 1, 0, 0] = [-3, -2, 0, 1]
        printf("Result: ");
        for (size_t i = 0; i < v->n; i++) {
                printf(" [%zd -> %2.2lf] ", v->index[i], v->a[i]);
        }

        free(w);
        free_vector(&v);
        free_vector(&u);
        return 0;
}
