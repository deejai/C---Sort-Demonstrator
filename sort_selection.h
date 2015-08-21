#ifndef _sort_selection_h_
#define _sort_selection_h_

#include "print_ints.h";

void sort_selection( int *nums, int length )
{
    // Perform selection sort and print array after
    // every insertion

    printf("   SELECTION avg: O(n^2)\n");

    int temp;
    int i, j;
    for( i=0; i<length; i++ ){
        for( j=i+1; j<length; j++ ){
            // First separator for sorted | unsorted
            // Second seperator for unsorted traversal
            print_ints( nums, (i+1), (i+1) );
            print_ints( &nums[i+1], length-(i+1), j-(i+1) );
            printf("\n");

            if( nums[j] < nums[i] ){
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
    }
    print_ints( nums, length, length );
    printf(" |\n\n");
}

#endif