#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "rodcut.h"

int main(int argc, char **argv) {

    int rod_length = 0;

    int piece_length = 0;

    int piece_price = 0;

    //int cut_count = 0;

    //int list_size = 0;

    Vector possible_cuts = create_vector(sizeof(Cut_t));

    if (argc != 2) {
        printf("Please pass a rod length through the command line\n");
        return 1;
    }

    sscanf_s(argv[1], "%d", &rod_length);

    //printf("Rod length is %d\n", rod_length);
    
    while (!feof(stdin)) {
        if(2 != fscanf_s(stdin, "%d, %d", &piece_length, &piece_price))
            break; 
        //printf("I got here\n");

        if (piece_length > 0 || piece_price > 0) {
        
            Cut_t * new_cut = malloc(sizeof(Cut_t));

            new_cut->length = piece_length;
            new_cut->price = piece_price;

            vector_push_back(possible_cuts, new_cut);
        }
        else
            printf("Please enter a valid length and price\n");
    }

    Cut_t* cut_list = vector_get_data(possible_cuts);

    for (int ix = 0; ix < vector_length(possible_cuts); ix++) {
        printf("Piece %d, %d, %d", ix, cut_list[ix].length,
                cut_list[ix].price);
    }

    //printf("I'm done\n");
    // index = 0;

    int max_price = rod_cutting(rod_length, possible_cuts);

    printf("Max price: %d\n", max_price);

    destroy_vector(possible_cuts);

    return 0;
}