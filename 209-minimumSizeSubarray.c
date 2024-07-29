/*
 * Author: Angad Dogra
 * We are defined by our choices, not by our abilities.
 *
 */

int minSubArrayLen(int target, int* nums, int numsSize) {
    // to do this shiz with sliding window

    int start = 0, end, sum = 0;
    int minLength = numsSize + 1 ;
    for (end = 0; end < numsSize ; end++) {
        sum += nums[end] ;
        while (sum >= target) {
            int currentLength = (end - start) + 1 ;
            if (currentLength < minLength) {
                minLength = currentLength ;
            }
            sum -= nums[start] ;
            start++ ;
        }
    }
    return (minLength == numsSize + 1) ? 0 : minLength ;
}
