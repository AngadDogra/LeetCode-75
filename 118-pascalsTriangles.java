class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<>();
        if (numRows == 0) return triangle;
        List<Integer> firstRow = new ArrayList<>();
        firstRow.add(1);
        triangle.add(firstRow);

        // at this point we have the first row of the pascal triangle
        for (int i = 1; i < numRows; i++){
            List<Integer> prevRow = triangle.get(i - 1);  // start from 1
            List<Integer> currRow = new ArrayList<>();
            currRow.add(1);                                   // the first element is 1 in every row
            for (int j = 1; j < i; j++){
                currRow.add(prevRow.get(j-1)+ prevRow.get(j));
            }
            currRow.add(1);
            triangle.add(currRow);
        }
        return triangle;
    }
}
