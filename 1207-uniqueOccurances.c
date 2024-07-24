// i wanna feel what love is, i want you to show me

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct HashMap {
    int freq;
    int element;
};

bool uniqueOccurrences(int* arr, int arrSize) {
    // Allocate memory for the hashmap
    struct HashMap* hashMap = (struct HashMap*) malloc(arrSize * sizeof(struct HashMap));
    int hashMapSize = 0;

    // Initialize the frequencies to 0
    for (int i = 0; i < arrSize; i++) {
        hashMap[i].freq = 0;
    }

    // Count frequencies of elements
    for (int i = 0; i < arrSize; i++) {
        bool found = false;
        for (int j = 0; j < hashMapSize; j++) {
            if (hashMap[j].element == arr[i]) {
                hashMap[j].freq++;
                found = true;
                break;
            }
        }
        if (!found) {
            hashMap[hashMapSize].element = arr[i];
            hashMap[hashMapSize].freq = 1;
            hashMapSize++;
        }
    }

    // Check for unique frequencies
    for (int i = 0; i < hashMapSize; i++) {
        for (int j = i + 1; j < hashMapSize; j++) {
            if (hashMap[i].freq == hashMap[j].freq) {
                free(hashMap);
                return false;
            }
        }
    }

    free(hashMap);
    return true;
}

int main() {
    int arr[] = {1, 2, 2, 1, 1, 3};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    bool result = uniqueOccurrences(arr, arrSize);
    if (result) {
        printf("The array has unique occurrences.\n");
    } else {
        printf("The array does not have unique occurrences.\n");
    }

    return 0;
}

