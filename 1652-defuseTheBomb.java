class Solution {
    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        int [] codeTwice = new int [n * 2];
        int [] returnArray = new int[n];
        for (int i = 0; i < n * 2; i++){
            codeTwice[i] = code[i % n];
        }

        if (k > 0){
            // add the next n - 1 numbers
            for (int i = 0; i < n ; i++){
                for (int j = i + 1; j <= i + k ; j++){
                    
                    returnArray[i] += codeTwice[j]; 
                }
            }
        }
        else if (k < 0){
            // have to add the k previous numbers
            for (int i = 0; i < n; i++){
                for (int j = i - 1; j > i + k - 1; j--) {
                    returnArray[i] += codeTwice[j < 0 ? j + n : j]; 
                }
            }
        }
        /*
        for (int i = 0; i < n * 2; i++){
            System.out.print(codeTwice[i] + " ");
        }
        */

        for (int i = 0; i < n; i++){
            System.out.print(returnArray[i] + " ");
        }
        return returnArray;
    }
}
