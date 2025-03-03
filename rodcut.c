#include <stdio.h>
#include <stdlib.h>

#include "rodcut.h"
#include "vector.h"

// Uses recursion to find the most profitable cuts for the rod
// Inputs: rod_length - the length of the rod
//         cuts -      array of structs representing the possible
//                         cuts that can be made to the rod
// Output: the maximum price that can be obtained from cutting the rod

int rod_cutting(int rod_length, Vector cuts) {

    // make a list of cuts that are made to the rod and pass it to helper function

    int max_price = 0;
    int cut_count = 0;

    Cut_t* cuts_made = vector_get_data(cuts);

    size_t length = vector_length(cuts);

    max_price = rod_cutting_recursion(rod_length, cut_count, length, cuts_made);

    for (int i = 0; i < length; i++) {
        if (cuts_made[i].count > 0)
            printf("%d cuts of length %d\n", cuts_made[i].count, cuts_made[i].length);
    }

    return max_price;
}

// Helper function for rod_cutting
// Inputs: rod_length - the length of the rod
//         length - the number of possible cuts
//         cut_count - the number of cuts that are made to the rod
//         possible_cuts - array of structs representing the possible
//                         cuts that can be made to the rod
// Output: the maximum price that can be obtained from cutting the rod

// keep temporary list of cut details, and update it when a better price is found

int rod_cutting_recursion(int rod_length, int cut_count, size_t length, Cut_t* possible_cuts) {

    int max_price = 0;

    int price = 0;

    if (rod_length <= 0) {
        return 0;
    }

    for (int ix = 0; ix < length; ix++) {
        if (rod_length >= possible_cuts[ix].length) {

            // Recursively check every price combination to determine the most valuable set of cuts
            price = possible_cuts[ix].price + rod_cutting_recursion(rod_length - possible_cuts[ix].length,
                                                            cut_count++, length, possible_cuts);

            if (price > max_price) {
                max_price = price;

                possible_cuts[ix].count = cut_count;
            }
        }
        cut_count = 0;
    }

    return max_price;
}