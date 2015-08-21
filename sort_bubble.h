#ifndef _sort_bubble_h_
#define _sort_bubble_h_

#include "print_ints.h"

void sort_bubble( int *nums, int length )
{
    // Perform bubble sort and print array after
    // every swap test

    printf("   BUBBLE avg: O(n^2)\n");
    print_ints( nums, length, 0, 0 );

    int temp;
    int i, j=length;
    int did_swap = 1;

    while( j>0 && did_swap ){
        did_swap = 0;
        for( i=1; i<j; i++ ){
            if( nums[i-1]>nums[i] ){

                temp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = temp;

                did_swap = 1;
            }
            print_ints( nums, length, i, i );
        }
        j--;
    }
}

#endif
