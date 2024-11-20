/*
So you can take one character either from left or from right
*/
class Solution {
    public int takeCharacters(String s, int k) {
        Map<Character,Integer> map = new HashMap<>();
        map.put('a',0);
        map.put('b',0);
        map.put('c',0);
        for (char c: s.toCharArray()){
            map.put(c, map.get(c) + 1);
        }
        
        // we now have frequencies of each element
        if (map.get('a') < k || map.get('b') < k || map.get('c') < k){
            return -1;
        }

 // Step 3: Sliding window to find the largest valid subarray
        int n = s.length();
        int left = 0, maxWindowLength = 0;
        Map<Character, Integer> windowCount = new HashMap<>();
        windowCount.put('a', 0);
        windowCount.put('b', 0);
        windowCount.put('c', 0);

        for (int right = 0; right < n; right++) {
            // Expand the window by adding the current character
            char rightChar = s.charAt(right);
            windowCount.put(rightChar, windowCount.get(rightChar) + 1);

            // Shrink the window if any character exceeds the allowed remaining count
            while (windowCount.get('a') > map.get('a') - k ||
                   windowCount.get('b') > map.get('b') - k ||
                   windowCount.get('c') > map.get('c') - k) {
                char leftChar = s.charAt(left);
                windowCount.put(leftChar, windowCount.get(leftChar) - 1);
                left++;
            }

            // Update the maximum window length
            maxWindowLength = Math.max(maxWindowLength, right - left + 1);
        }

        // Step 4: Calculate the minimum time required
        return n - maxWindowLength;
    }
}
