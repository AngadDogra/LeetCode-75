class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        int sum = 0;
        int maxNum = quantities[0];
        for (int i = 0 ; i < quantities.length; i++){
            sum += quantities[i] ; 
            int current = quantities[i];
            if (current > maxNum){
                maxNum = current; 
            }
        }
        int left = 1;
        int right = maxNum;
        int result = maxNum;
        while (left <= right){
            int mid = (left + right)/2; 
            int req_stores = 0;
            for (int num : quantities){
                req_stores += (num+mid-1)/mid; 
            }
            if (req_stores <= n){
                result = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return result;
    }
}
