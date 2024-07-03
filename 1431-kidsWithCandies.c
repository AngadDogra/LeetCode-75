#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    // candies[i] + extraCandies >= maxCandies ; return true ;
    bool* returnedCandies = (bool *) malloc (candiesSize * sizeof (bool)) ;

    int maxCandies = candies[0] ;
    for (int i = 1 ; i < candiesSize ;i++){
        if (candies[i] >= maxCandies) {
            maxCandies = candies[i] ;
        }
    }

    for (int i = 0 ; i < candiesSize ;i++){
        if (candies[i] + extraCandies >= maxCandies) {
            returnedCandies[i] = true ;
        } else {
            returnedCandies[i] = false ;
        }
    }

    *returnSize = candiesSize ;

    return returnedCandies ;
        
}

int main () 
{
    int candiesSize = 5 ;
    int candies[5] = {2, 3, 5, 1, 3} ;
}