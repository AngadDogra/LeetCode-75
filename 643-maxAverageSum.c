double findMaxAverage(int* nums, int numsSize, int k) {
    // Initial sum of the first window
    int currentSum = 0;
    for (int i = 0; i < k; i++) {
        currentSum += nums[i];
    }

    int maxSum = currentSum;

    // Sliding the window across the array
    for (int i = k; i < numsSize; i++) {
        currentSum += nums[i] - nums[i - k];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    // Return the maximum average
    return (double)maxSum / k;
}