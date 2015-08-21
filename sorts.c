#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void sort_insertion( int *nums, int length )
{
    printf("   INSERTION avg: O(n^2)\n");
    print_ints( nums, length, 0, 0 );

    int i, j, temp;
    for( i=1; i<length; i++ ){

        temp = nums[i];
        j = i;

        while( (nums[j-1] > temp) ){
            nums[j] = nums[j-1];
            
            j--;
            if( j<=0 ) break;
        }
        nums[j] = temp;

        print_ints( nums, length, i, i );
    }
    printf("\n");
}

void sort_bubble( int *nums, int length )
{
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

int main( int argc, char *argv[] )
{
    int i, nums[argc-1];
    for( i=1; i<argc; i++ ){
        nums[i-1] = atoi(argv[i]);
    }

    printf("\n");
    demo_sort( sort_insertion, nums, argc-1 );
    demo_sort( sort_bubble, nums, argc-1 );

    return 0;
}