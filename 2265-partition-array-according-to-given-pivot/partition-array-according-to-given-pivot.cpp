class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>less;
        vector<int>equal;
        vector<int>great;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i] < pivot)
            {
                less.push_back(nums[i]);
            }
            if(nums[i] == pivot)
            {
                equal.push_back(nums[i]);
            }
            if(nums[i] > pivot)
            {
                great.push_back(nums[i]);
            }
        }
        for(auto it:equal)
        {
            less.push_back(it);
        }
        for(auto it:great)
        {
            less.push_back(it);
        }
        return less;
    }
};