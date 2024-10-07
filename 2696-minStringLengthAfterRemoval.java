class Solution {
    public int minLength(String s) {
        boolean flag = true;

        while(flag){
            flag = false;

            for (int i = 0 ; i < s.length()-1; i++){
                if (s.charAt(i) == 'A' && s.charAt(i+1) == 'B'){
                    s = s.substring(0, i) + s.substring(i+2);
                    flag = true;
                    break;
                }
                if (s.charAt(i) == 'C' && s.charAt(i+1) == 'D'){
                    s = s.substring(0, i) + s.substring(i+2);
                    flag = true;
                    break;
                }
            }
        }

        return s.length();
    }
}
