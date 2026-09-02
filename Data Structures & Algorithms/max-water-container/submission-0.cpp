class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_water = 0;       // Keeps track of the largest area found
        int left = 0;            // Starts at the far left
        int right = heights.size() - 1; // Starts at the far right
        
        while (left < right) {
            // The height of the water is limited by the shorter bar
            int current_height = min(heights[left], heights[right]);
            int current_width = right - left;
            
            // Calculate current area and update max_water if it's larger
            int current_area = current_width * current_height;
            max_water = max(max_water, current_area);
            
            // Move the pointer that points to the shorter bar inward
            // to potentially find a taller bar and increase the area
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};