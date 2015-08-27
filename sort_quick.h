#ifndef _sort_quick_h_
#define _sort_quick_h_

#include "print_ints.h"

void swap( int *a, int *b )
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void recursive_quick( int *nums, int length )
{
    if( length<=1 ){
        return;
    }

    // choose random pivot by swapping an int from a
    // random position into the rightmost slot
    swap( nums[ length-1 ], nums[ rand()%length ] );

    // if current num is <= pivot, swap it with
    // num at part_index and increment part_index
    int i;
    int part_index = 0;
    for( i=0; i<length; i++ ){
        if( nums[i] <= nums[part_index] ){
            swap( &nums[i], &nums[part_index] );
            part_index++;
        }
    }
    // swap pivot into place
    swap( nums[length-1], nums[part_index] );

    // print nums with partition indicators around pivot
    print_ints( nums, part_index, part_index );
    print_ints( &nums[part_index], length-part_index, 0 );
    printf("\n");

    recursive_quick( nums, left_length );
    recursive_quick( pivot+1, right_length );
}

void sort_quick( int *nums, int length )
{
    // Perform quick sort and print array after
    // every swap check

    printf("   QUICK avg: O(n logn)\n");
    print_ints( nums, length, 0 );

    recursive_quick( nums, length );

    printf("\n\n");
}

#endif