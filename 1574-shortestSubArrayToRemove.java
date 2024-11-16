class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        // find both of the inflection points
        // inc - dec and dec - inc
        int N = arr.length;
        int prefixPos=0;
        
        while (prefixPos < N - 1 && arr[prefixPos] <= arr[prefixPos+1]){
            prefixPos++; 
        }
        if (prefixPos == N - 1){
            return 0;
        }

        int suffixPos= N - 1;
        while (suffixPos > 0 && arr[suffixPos] >= arr[suffixPos-1]){
            suffixPos--;
        }

        // suffixPos and prefixPos have been calculated
        int minLen = Math.min(N-prefixPos-1, suffixPos);

        int i=0;
        int j = suffixPos;

        while (i <= prefixPos && j < N){
            if (arr[i] <= arr[j]){
                minLen = Math.min(minLen, j-i-1);
                i++;
            } else {
                j++; 
            }
        }
        return minLen;
    }   
}
