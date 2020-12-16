#include <stdlib.h>

typedef struct {
        size_t  size;           /* Size of index and a arrays */
        size_t  n;              /* Nbr of used elements of the arrays */
        size_t* index;          /* Array of element indices */
        double* a;              /* Array of non-zero elements */
} vector_t;

double* w;

vector_t* new_vector(int size, double* array);
void vector_scalar_sub(vector_t* v, vector_t* u, double s);
void free_vector(vector_t** v);
