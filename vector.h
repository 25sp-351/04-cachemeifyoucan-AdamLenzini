#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct vector {
    void* data;
    size_t data_size;
    size_t capacity;
    size_t length;
} *Vector;

Vector create_vector(size_t data_size);

Vector copy_vector(Vector old_vec);

void destroy_vector(Vector vector);

size_t vector_length(Vector vector);

void vector_push_back(Vector vector, void* data);

// void vector_pop_back(Vector vector);

//void* vector_get(Vector vector, int index);

void* vector_get_data(Vector vector);

#endif