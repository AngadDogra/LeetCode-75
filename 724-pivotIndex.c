#include <stdio.h>
#include <stdlib.h>

int pivotIndex(int* nums, int numsSize) {
    // Calculate the prefix sum and then comparing i - 1 and i + 1
    int* sumLeft = (int *) malloc (numsSize * sizeof (int)) ;
    int* sumRight = (int *) malloc (numsSize * sizeof (int)) ;

    sumLeft[0] = nums[0] ;
    sumRight[numsSize - 1] = nums [numsSize - 1] ;    

    for (int i = 1 ; i < numsSize ; i++) {
        sumLeft[i] = nums[i] + sumLeft[i - 1]   ;
    }

    for (int i = numsSize - 2 ; i >= 0 ; i--) {
        sumRight[i] = nums[i] + sumRight[i + 1] ;
    }

    printf ("\nThe sumLeft array is: ") ;
    for (int i = 0 ; i < numsSize ; i++) {
        printf("%d ", sumLeft[i]) ;
    }

    printf ("\nThe sumRight array is: ") ;
    for (int i = 0 ; i < numsSize ; i++) {
        printf("%d ", sumRight[i]) ;
    }

    for (int i = 0 ; i < numsSize ; i++) {
        if (sumRight[i] == sumLeft[i]) {
            return i ;
        }
    }
    return -1 ;
}

int main () 
{
    int nums[6] = {1, 7, 3, 6, 5, 6} ;
    int numsSize = sizeof (nums) / sizeof (nums[0]) ;
    
    int result = pivotIndex (nums, numsSize) ;
    printf("\nThe returned value is : %d", result) ;

    return 0 ; 
}
