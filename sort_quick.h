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
    int pivot = rand() % length;
    swap( &nums[ length-1 ], &nums[ pivot ] );

    // print nums with partition indicator before pivot
    printf("choose pivot: ");
    print_ints( nums, length, length-1 );
    printf("\n");

    // if current num is <= pivot, swap it with
    // num at p_index and increment p_index
    int i;
    int p_index = 0;
    for( i=0; i<length-1; i++ ){
        if( nums[i] <= nums[length-1] ){
            swap( &nums[i], &nums[p_index] );
            p_index++;
        }
    }
    // swap pivot into place
    swap( &nums[length-1], &nums[p_index] );

    // print nums with partition indicators around pivot
    printf("...partition: ");
    print_ints( nums, p_index, p_index-1 );
    printf("|"); // part without trailing space
    print_ints( &nums[p_index], length-p_index, -1 );
    printf("\n");

    recursive_quick( nums, p_index );

    if( p_index+1 < length )
        recursive_quick( &nums[p_index+1], length - (p_index+1) );
}

void sort_quick( int *nums, int length )
{
    // Perform quick sort and print array after
    // every swap check

    srand(time(NULL));

    // Header
    printf("   QUICK avg: O(n logn)\n");
    print_ints( nums, length, -1 );
    printf("\n");

    if( length > 1 ){
        recursive_quick( nums, length );
        print_ints( nums, length, -1 );
    }

    printf("\n\n");
}

#endif