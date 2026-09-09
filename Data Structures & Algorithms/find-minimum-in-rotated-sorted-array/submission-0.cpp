class Solution {
   public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < ans) {
                ans = nums[mid];
            }
            if (nums[mid] < nums[right]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};