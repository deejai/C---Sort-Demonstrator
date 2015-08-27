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
    // num at p_index and increment p_index
    int i;
    int p_index = 0;
    for( i=0; i<length; i++ ){
        if( nums[i] <= nums[p_index] ){
            swap( &nums[i], &nums[p_index] );
            p_index++;
        }
    }
    // swap pivot into place
    swap( nums[length-1], nums[p_index] );

    // print nums with partition indicators around pivot
    print_ints( nums, p_index, p_index );
    print_ints( &nums[p_index], length-p_index, 0 );
    printf("\n");

    recursive_quick( nums, p_index );
    recursive_quick( &nums[ p_index+1 ], length - (p_index+1) );
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