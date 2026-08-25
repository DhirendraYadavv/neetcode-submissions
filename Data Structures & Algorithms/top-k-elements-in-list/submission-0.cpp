class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: The Tally (Count them up)
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        // Step 2: The Boxes
        // Create an array of empty vectors (boxes). 
        // Size is nums.size() + 1 because the max frequency is the size of the array.
        vector<vector<int>> boxes(nums.size() + 1);
        
        // Put numbers into the box matching their frequency
        for (auto& [num, frequency] : count) {
            boxes[frequency].push_back(num);
        }
        
        // Step 3: Walk Backward
        vector<int> result;
        // Start from the last box (highest frequency) and walk down to 1
        for (int i = boxes.size() - 1; i > 0; --i) {
            for (int num : boxes[i]) {
                result.push_back(num);
                // Stop once we have exactly 'k' elements
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result; 
    }
};