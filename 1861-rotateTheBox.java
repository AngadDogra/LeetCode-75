class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int rows = box.length;
        int cols = box[0].length;

        // Step 1: Simulate gravity for each row
        for (int i = 0; i < rows; i++) {
            int empty = cols - 1; // Position to place the next stone
            for (int j = cols - 1; j >= 0; j--) {
                if (box[i][j] == '#') { // If stone, move it to the farthest right
                    box[i][j] = '.';
                    box[i][empty--] = '#';
                } else if (box[i][j] == '*') { // If obstacle, reset the empty pointer
                    empty = j - 1;
                }
            }
        }

        // Step 2: Rotate the box 90 degrees clockwise
        char[][] rotatedBox = new char[cols][rows];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rotatedBox[j][rows - i - 1] = box[i][j];
            }
        }

        return rotatedBox;
    }
}

