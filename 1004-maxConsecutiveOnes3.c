int longestOnes(int* nums, int numsSize, int k) {
    // Dynamic window size right
    // Size of the window increases as long we encounter 1s
    // Still increases as you encounter 0s < k 
    // As soon as 0s == k , go to i - 1 and store the length

    int left = 0, right = 0 ;
    int maxLength = 0 ;          // left and right pointers

    for (right = 0 ; right < numsSize ; right++) {
        if (nums[right] == 0) {
            k-- ;
        }
        while ( k < 0) {
            if (nums[left] == 0) {
                k++ ;
            }
            left++ ;
        }

        maxLength = (right - left + 1) > maxLength ? (right - left + 1) : maxLength;
    }
    return maxLength ;
}