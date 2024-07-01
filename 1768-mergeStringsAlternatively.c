#include <stdio.h>
#include <stdlib.h>

/*You are given two strings word1 and word2. 
Merge the strings by adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.*/

char * mergeAlternately(char * word1, char * word2){
    
   // two pointers: one tracks the first array and the other tracks the second one
   // if second is bigger than first then print the remaining characters of second
   // in any case we will need space for m + n.

 

   int sizeOfWord1 = 0 ;
   int sizeOfWord2 = 0 ;


   while (word1[sizeOfWord1]!= '\0') {
    sizeOfWord1++ ;
   }

   while (word2[sizeOfWord2] != '\0') {
    sizeOfWord2++ ;
   }   

   char* combined = (char*) malloc (sizeOfWord1+sizeOfWord2+1 * (sizeof (char))) ;
   if (combined == NULL){
        return NULL ;
   }
   
   int i = 0, j = 0, k = 0 ;

   while (i < sizeOfWord1 && j < sizeOfWord2) {
        combined[k++] = word1[i++] ;
        combined[k++] = word2[j++] ;
   }

    // Appending characters from word1
    while (i < sizeOfWord1) {
        combined[k++] = word1[i++] ;
    }

    while (j < sizeOfWord2) {
        combined[k++] = word2[j++] ;
    }

    combined[k] = '\0' ;

   return combined ;

}
