bool increasingTriplet(int* nums, int numsSize) {
    // Early exit if the array has fewer than 3 elements
    if (numsSize < 3) {
        return false;
    }

    int first = INT_MAX;
    int second = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= first) {
            first = nums[i];  // update first if nums[i] is smaller
        } else if (nums[i] <= second) {
            second = nums[i];  // update second if nums[i] is larger than first but smaller than second
        } else {
            return true;  // a triplet is found
        }
    }

    return false;  // no triplet found
}
