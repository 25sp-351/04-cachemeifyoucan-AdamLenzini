#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

// Cuts that the user inputs as a possiblity for the rod
// length - the length of the cut
// price - how much the cut is valued
// count - the number of cuts of that length
typedef struct Cut {
    int length;
    int price;
    int count;
} Cut_t;

int rod_cutting(int rod_length, Vector possible_cuts);

int rod_cutting_recursion(int rod_length, int cut_count, size_t vector_length, Cut_t* possible_cuts);