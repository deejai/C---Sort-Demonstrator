#ifndef _insertion_sort_h_
#define _insertion_sort_h_

void sort_insertion( int *nums, int length )
{
    // Perform insertion sort and print array after
    // every new insertion

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

#endif
