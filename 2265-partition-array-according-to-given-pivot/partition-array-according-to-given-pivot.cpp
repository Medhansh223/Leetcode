class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int countless = 0;
        int countequal = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] < pivot)
            {
                countless++;
            }
            if(nums[i] == pivot)
            {
                countequal++;
            }
        }
        vector<int>ans(n);
        int i = 0;
        int j = countless;
        int k = countless + countequal;
        for(auto it:nums)
        {
            if(it < pivot)
            {
                ans[i] = it;
                i++;
            }
            if(it == pivot)
            {
                ans[j] = it;
                j++;
            }
            if(it > pivot)
            {
                ans[k] = it;
                k++;
            }
        }
        return ans;
    }
};