#ifndef _print_ints_h_
#define _print_ints_h_

#include <stdio.h>

void print_ints( int *nums, int length, int partition )
{
    // Print the given integer array along with a
    // partition separator

    // For no partition, pass -1 for partition

    printf(" ");

    int i;
    for( i=0; i<length; i++ ){
        if( partition==i )
            printf("| ");
        printf("%d ", nums[i]);
    }
    if( partition==length )
        printf("| ");
}

#endif
