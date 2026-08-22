class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        
        for (int i = 0; i < nums.size(); i++) {
            
            // Check if the "missing piece" is already in the map
            if (mpp.count(target - nums[i])) {
                return {mpp[target - nums[i]], i};
            }
            
            // If not, write the current number into the map
            mpp[nums[i]] = i;
        }
        
        return {}; // Return empty vector if no match (shorter than {-1, -1})
    }
};