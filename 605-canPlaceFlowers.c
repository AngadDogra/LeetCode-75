#include <stdio.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    
    int current, prev, next ;
    for (current = 0; current < flowerbedSize ; current++) {
        if (flowerbed[current] == 0) {
            prev = (current == 0) ? 0 : flowerbed[current - 1] ;
            next = (current == flowerbedSize - 1) ? 0 : flowerbed[current + 1] ;

            if (prev == 0 && next == 0) {
                flowerbed[current] = 1 ;
                n-- ;
            
                if (n == 0) {
                    return true ;
                }            
            }            

        }


    }

    return n <= 0 ;
   
}