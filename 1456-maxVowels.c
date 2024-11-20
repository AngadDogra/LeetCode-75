#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isVowel (char c) 
{
    return (c == 'a' || c =='e' || c =='i' || c =='o' || c =='u') ;         
}

int maxVowels(char* s, int k) 
{
    // count the vowels in the first substring of length k.
    int currentVowels = 0 ;
    int length = strlen(s) ;
    for (int i = 0 ; i < k ; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] == 'o' || s[i] == 'u') {
            currentVowels++ ;
        }   
    }

    int maxVowels = currentVowels ;
    for (int i = k ; i < length ; i++) {
        if (isVowel(s[i])) {
            currentVowels++ ;
        }
        if (isVowel(s[i-k])) {
            currentVowels-- ;
        }
        if (currentVowels > maxVowels) {
            maxVowels = currentVowels ;
        }
    }

    return maxVowels ;
}

int main ()
{
    char s[] = "abciiidef" ;
    int result = maxVowels(s, 3) ;
    printf("The result is %d", result) ; 
}