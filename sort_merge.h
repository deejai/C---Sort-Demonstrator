#ifndef _sort_merge_h_
#define _sort_merge_h_

#define NEXT_LEFT (nums[mid-left_ints])
#define NEXT_RIGHT (nums[length-right_ints])
#define NEXT_SORTED (sorted[length-left_ints-right_ints])

#include "print_ints.h"

void merge_sorted_halves( int *nums, int length )
{
    // Trackers for midpoint and remaining int counts
    int mid = length/2;
    int left_ints = mid;
    int right_ints = length-mid;

    // Temp array for placing sorted ints
    int *sorted = malloc(sizeof(int)*length);

    int i;
    for( i=0; i<length; i++ ){
        // If both lists have ints
        if( left_ints > 0 && right_ints > 0 ){
            // Consume next left int if it is smaller
            if( NEXT_LEFT < NEXT_RIGHT ){
                NEXT_SORTED = NEXT_LEFT;
                left_ints--;
            }
            // Else consume next right int
            else{
                NEXT_SORTED = NEXT_RIGHT;
                right_ints--;
            }
        }
        // Else consume the next int of the remaining half
        else{
            if( left_ints > 0 ){
                NEXT_SORTED = NEXT_LEFT;
                left_ints--;
            }
            else{
                NEXT_SORTED = NEXT_RIGHT;
                right_ints--;
            }
        }
    }

    // Transfer sorted ints into original array
    for( i=0; i<length; i++ ){
        nums[i] = sorted[i];
    }

    free(sorted);
}

void recursive_merge( int *nums, int length )
{
    if( length==1 ){
        return;
    }
    print_ints( nums, length, length/2 );
    printf("\n");
    recursive_merge( nums, length/2 );
    recursive_merge( &nums[length/2], length-(length/2) );
    merge_sorted_halves( nums, length );
}

void sort_merge( int *nums, int length )
{
    // Perform merge sort and print array after
    // every separation and merge operation

    printf("   MERGE avg: O(n logn)\n");

    recursive_merge( nums, length );

    print_ints( nums, length, length/2 );
    printf("\n\n");
}

#endif