int minimumDeletions(char* s) {
    int length = strlen(s);
    if (length == 0 || length == 1) {
        return 0;
    }

    int* prefixB = (int *) malloc(length * sizeof(int));
    int* suffixA = (int *) malloc(length * sizeof(int));

    // Calculate the prefix b's
    prefixB[0] = (s[0] == 'b') ? 1 : 0;
    for (int i = 1; i < length; i++) {
        prefixB[i] = prefixB[i - 1] + (s[i] == 'b');
    }

    // Calculate the suffix a's
    suffixA[length - 1] = (s[length - 1] == 'a') ? 1 : 0;
    for (int i = length - 2; i >= 0; i--) {
        suffixA[i] = suffixA[i + 1] + (s[i] == 'a');
    }

    // Find the minimum deletions
    int minDeletions = length; // Maximum possible deletions
    for (int i = 0; i < length - 1; i++) {
        int deletions = prefixB[i] + suffixA[i + 1];
        if (deletions < minDeletions) {
            minDeletions = deletions;
        }
    }

    // Consider the case where all characters are 'a' or all are 'b'
    minDeletions = (minDeletions < prefixB[length - 1]) ? minDeletions : prefixB[length - 1];
    minDeletions = (minDeletions < suffixA[0]) ? minDeletions : suffixA[0];

    free(prefixB);
    free(suffixA);

    return minDeletions;
}
