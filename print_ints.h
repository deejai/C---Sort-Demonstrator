#ifndef _print_ints_h_
#define _print_ints_h_

#include <stdio.h>


void print_ints( int *nums, int length, int partition_a,
                                        int partition_b )
{
    // Print the given integer array along with up to two
    // partition indicators

    printf(" ");

    int i;
    for( i=0; i<length; i++ ){
        printf("%d ", nums[i]);
        if( i==partition_a || i==partition_b )
            printf("| ");
    }

    printf("\n");
}

#endif