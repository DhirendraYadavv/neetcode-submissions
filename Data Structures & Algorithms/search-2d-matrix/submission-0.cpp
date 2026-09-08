class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> result;
        for(auto x : matrix)
        {
            for(int i = 0; i < x.size(); i++)
            {
                result.push_back(x[i]);
            }
        }

        int left = 0;
        int right = result.size();

        while(left < right)
        {
            int mid = left +(right - left)/2;

            if(result[mid] == target)
            {
                return true;
            }

            if(result[mid] < target)
            {
                left ++;
            }
            else{
                right --;
            }
        }
        return false;
    }
};