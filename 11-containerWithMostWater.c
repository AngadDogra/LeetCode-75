// angad dogra : solved on the 18th of July2024
#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;
    
    while (left < right) {
        // Calculate the current area
        int current_height = (height[left] < height[right]) ? height[left] : height[right];
        int current_area = current_height * (right - left);
        
        // Update the maximum area if current area is larger
        if (current_area > max_area) {
            max_area = current_area;
        }
        
        // Move the pointer pointing to the shorter line inward
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_area;
}

