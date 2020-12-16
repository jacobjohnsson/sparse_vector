#include "vector.h"
#include <stdlib.h>

void vector_scalar_sub(vector_t* v, vector_t* u, double s)
{
        int i,j;
        for (size_t i = 0; i < u->n; i++) {
                w[u->index[i]] = u->a[i];
        }
        for (size_t i = 0; i < v->n; i++) {
                j = v->index[i];
                if (w[j] != 0) {
                        v->a[i] -= s * w[i];
                        w[j] = 0;
                }
        }
        for (size_t i = 0; i < u->n; i++) {
                j = u->index[i];
                if (w[j] != 0) {

                        // Reallocate v->a and v->index.
                        if (v->n == v->size) {
                                size_t new_size = v->size * 2;
                                size_t* new_index = malloc(new_size * sizeof(size_t));
                                double* new_a = malloc(new_size * sizeof(double));

                                for (size_t i = 0; i < v->size; i++) {
                                        new_index[i] = v->index[i];
                                        new_a[i] = v->a[i];
                                }

                                free(v->index);
                                free(v->a);

                                v->size = new_size;
                                v->index = new_index;
                                v->a = new_a;
                        }

                        v->a[v->n] = s * -w[j];
                        v->index[v->n] = j;
                        v->n += 1;
                        w[j] = 0;
                }
        }
}

vector_t* new_vector(int size, double* array) {
        vector_t* v = malloc(sizeof(vector_t));

        size_t n = 0;
        for (size_t i = 0; i < (size_t)size; i++) {
                if (array[i] != 0) {
                        n++;
                }
        }

        v->size  = n;
        v->index = malloc(n * sizeof(size_t));
        v->a     = malloc(n * sizeof(double));
        v->n = n;

        size_t count = 0;
        for (size_t i = 0; i < size; i++) {
                if (array[i] != 0) {
                        v->index[count] = i;
                        v->a[count] = array[i];
                        count++;
                }
        }
        return v;
}

void free_vector(vector_t** v)
{
        free((*v)->index);
        free((*v)->a);
        free(*v);
        *v = NULL;
}
