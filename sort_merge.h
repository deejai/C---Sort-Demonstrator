#ifndef _sort_merge_h_
#define _sort_merge_h_

#include "print_ints.h";

int *merge_sorted( int *nums_a, int len_a,
                   int *nums_b, int len_b )
{
    // Function for merging two sorted lists of integers.
    // Places next largest value before the last placed value.

    int length = len_a + len_b;
    int *nums = malloc(sizeof(int)*length);

    int i;
    for( i=length; i>0; i-- ){
        if( len_a>0 && len_b>0 ){
            // else if neither array has been exhausted
            if( nums_a[len_a-1] > nums_b[len_b-1] ){
                // if nums_a has larger num, use nums_a
                nums[i-1] = nums_a[len_a-1];
                len_a--;
            }
            else{
                // else use nums_b
                nums[i-1] = nums_b[len_b-1];
                len_b--;
            }
        }
        else{
        // else use non-exhausted array
            if( len_a>0 ){
                nums[i-1] = nums_a[len_a-1];
                len_a--;
            }
            else{
                nums[i-1] = nums_b[len_b-1];
                len_b--;
            }
        }
    }
    return nums;
}

int *recursive_merge( int *nums, int length )
{
    if( length==1 ){
        printf("%d|", nums[0]);
        return nums;
    }
    merge_sorted(
        recursive_merge( nums, length/2 ),
        length/2,

        recursive_merge( &nums[length/2], length-(length/2) ),
        length - (length/2)
    );
}

void sort_merge( int *nums, int length )
{
    // Perform merge sort and print array after
    // every separation and merge operation

    printf("   MERGE avg: O(n logn)\n");

    nums = recursive_merge( nums, length );

    print_ints( nums, length, length/2 );
    printf("\n\n");
}

#endif