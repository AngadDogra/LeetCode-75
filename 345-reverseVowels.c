// bool isVowel (char c) {
//     return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
//            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
// }

// void swap (char* a, char* b) {
//     char temp = *a ;
//     *a = *b ;
//     *b = temp ;
// }

// char* reverseVowels(char* s) {
//     char* first = s ;
//     char* second = s + strlen(s) - 1 ;

// while (first < second) {
//     // Move the first pointer to the next vowel
//     while (first < second && !isVowel(*first)) {
//         first++;
//     }
    
//     // Move the second pointer to the previous vowel
//     while (first < second && !isVowel(*second)) {
//         second--;
//     }
    
//     // Swap the vowels
//     if (first < second) {
//         swap(first, second);
//         first++;
//         second--;
//         }
//     }
//     return s ;
// }