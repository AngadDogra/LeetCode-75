int max(int a, int b) {
    return (a > b) ? a : b;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;          // Edge case: No houses to rob
    if (numsSize == 1) return nums[0];    // Edge case: Only one house to rob

    int *dp = (int *)malloc(numsSize * sizeof(int));
    if (!dp) {
        // Handle memory allocation failure
        return -1;
    }

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < numsSize; i++) {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    int result = dp[numsSize - 1];
    free(dp); // Free the allocated memory
    return result;
}
