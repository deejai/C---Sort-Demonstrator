#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "sort_insertion.h"
#include "sort_selection.h"
#include "sort_bubble.h"
#include "sort_merge.h"
#include "sort_quick.h"

void demo_sort( void (*function)(int*,int), int *nums, int length )
{
    // Show how the array would be sorted without
    // altering the original array

    // copy nums into new memory block
    int *nums_copy = malloc(sizeof(int)*length);

    int i;
    for ( i=0; i<length; i++)
        nums_copy[i] = nums[i];

    // call sort function on copied integer array
    (*function)( nums_copy, length );

    // free copied array
    free( nums_copy );
}

int main( int argc, char *argv[] )
{
    // Convert number strings to integers
    int i, nums[argc-1];
    for( i=1; i<argc; i++ ){
        nums[i-1] = atoi(argv[i]);
    }

    // Demonstrate each sort inside demo_sort wrapper
    printf("\n");
    demo_sort( sort_insertion, nums, argc-1 );
    demo_sort( sort_selection, nums, argc-1 );
    demo_sort( sort_bubble, nums, argc-1 );
    demo_sort( sort_merge, nums, argc-1 );
    demo_sort( sort_quick, nums, argc-1 );

    return 0;
}