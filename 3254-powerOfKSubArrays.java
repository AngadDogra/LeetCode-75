class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length;
        int [] result = new int [n-k+1];
        

        for (int i = 0; i <= n-k ; i++){
            boolean isConsecutive = true;
            for (int j = i; j < i + k - 1; j++){
                if (nums[j] + 1 != nums[j+1]){
                    isConsecutive = false; 
                    break;
                }
            }
            if (isConsecutive){
                result[i] = nums[i+k-1]; 
            }
            else{
                result[i] = -1; 
            }
        }
        return result;
    }
}
