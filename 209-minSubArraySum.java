class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int res = Integer.MAX_VALUE; 
        int start = 0;
        int currentSum = 0;
        for (int end = 0; end < nums.length; end++){
            currentSum += nums[end];

            while (currentSum >= target){
                res = Math.min(res, end - start + 1);
                currentSum -= nums[start];
                start++;
            }
        }

        return (res == Integer.MAX_VALUE)?0:res;
    }
}
