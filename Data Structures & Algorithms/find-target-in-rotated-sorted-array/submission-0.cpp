#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            // Avoid potential integer overflow compared to (low + high) / 2
            int mid = low + (high - low) / 2;

            // Found the target directly at the midpoint
            if (nums[mid] == target) {
                return mid;
            }

            // ========================================================
            // KEY IDEA: At least one half of a rotated sorted array
            // is ALWAYS normally sorted. We check which one it is.
            // ========================================================

            // Case 1: The LEFT half [low ... mid] is sorted
            if (nums[low] <= nums[mid]) {
                // Check if the target sits within this sorted left range: [nums[low], nums[mid])
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // Yes -> Target is in the left half, discard right
                } else {
                    low = mid + 1;  // No  -> Target must be in the right half, discard left
                }
            }
            // Case 2: The RIGHT half [mid ... high] is sorted
            else {
                // Check if the target sits within this sorted right range: (nums[mid], nums[high]]
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // Yes -> Target is in the right half, discard left
                } else {
                    high = mid - 1; // No  -> Target must be in the left half, discard right
                }
            }
        }

        // Target was not found anywhere in the array
        return -1;
    }
};