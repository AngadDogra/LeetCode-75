// Function to check if a character is alphanumeric
bool isAlphaNumeric(char c) {
    return isalnum(c);
}

// Function to check if the given string is a palindrome
bool isPalindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        // Move the left pointer to the next alphanumeric character
        while (left < right && !isAlphaNumeric(s[left])) {
            left++;
        }
        // Move the right pointer to the previous alphanumeric character
        while (left < right && !isAlphaNumeric(s[right])) {
            right--;
        }
        // Compare the characters
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
