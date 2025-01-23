class Solution {
    public int[] plusOne(int[] digits) {
        if (digits.length == 1 && digits[0] == 0){
            return new int[] {1};
        }
        for (int i = digits.length - 1; i >= 0; i--){
            if (digits[i] < 9){
                digits[i]+= 1;
                return digits;
            }
            digits[i] = 0;
        }
        int[] arr = new int[digits.length + 1];
        arr[0] = 1;
        return arr;
    }
}
