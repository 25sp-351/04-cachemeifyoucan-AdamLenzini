#include "vector.h"

#include <string.h>

#define CAPACITY 20

Vector create_vector(size_t data_size) {
    Vector vector = malloc(sizeof(struct vector));
    vector->data = NULL;
    vector->data_size = data_size;

    return vector;
}

Vector copy_vector(Vector old_vec) {
    Vector new_vec = create_vector(old_vec->data_size);
    new_vec->capacity = old_vec->capacity;
    new_vec->length = old_vec->length;
    size_t memory_length = new_vec->data_size * new_vec->capacity;
    new_vec->data = malloc(memory_length);
    memcpy(new_vec->data, old_vec->data, memory_length);

    return new_vec;
}

void destroy_vector(Vector vector) {
    if (vector->data != NULL)
        free(vector->data);
    free(vector);
}

size_t vector_length(Vector vector) {
    return vector->length;
}

void vector_push_back(Vector vector, void* data) {
    if (vector->data == NULL) {
        vector->capacity = CAPACITY;
        vector->data = malloc(vector->data_size * vector->capacity);
        vector->length = 0;
    }
    else if (vector->length == vector->capacity) {
        vector->capacity += CAPACITY;
        vector->data = realloc(vector->data, vector->data_size * vector->capacity);
    }

    memcpy(vector->data + (vector->length * vector->data_size), data, vector->data_size);
    vector->length++;
}

// void vector_pop_back(Vector vector) {
//     if (vector->length > 0) {
//         vector->length--;
//     }
// }

// void* vector_get(Vector vector, int index) {
//     if (vector->length > 0) {
//         return vector->data[index];
//     }

//     return NULL;
// }

void* vector_get_data(Vector vector) {
    return vector->data;
}