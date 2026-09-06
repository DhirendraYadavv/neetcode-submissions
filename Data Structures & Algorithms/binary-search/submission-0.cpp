class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            int mid = (left + right)/2;

            if(nums[mid] == target)
            {
                return mid;
            }

            if(nums[mid] < target)
            {
                left ++;
            }
            else{
                right --;
            }
        }
        return -1;
    }
};