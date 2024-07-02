#include <stdio.h>
#include <stdlib.h>

int largestAltitude(int* gain, int gainSize) {
    // find the prefix sum of the gain array
    // find max of the prefix sum array
    int * prefixGain = (int *) malloc (gainSize + 1 * (sizeof (int))) ; // as array size is one more
    prefixGain[0] == 0 ;
    int maxHeight = prefixGain[0] ; 
    for (int i = 0 ; i < gainSize ; i++) {
        prefixGain[i + 1] = prefixGain[i] +  gain[i] ; 
        if (prefixGain [i+1] > maxHeight) {
            maxHeight == prefixGain[i + 1] ;
        }
    }

    free(prefixGain) ;
    return maxHeight ;
}

int main ()
{
    int gain[5] = {-5, 1, 5, 0, -7} ;
    int gainSize = sizeof(gain) / sizeof (gain[0]) ;
    int result = largestAltitude (gain, gainSize); 

    printf("The result is : %d", result) ;
}