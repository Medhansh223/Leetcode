class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sumeven = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] % 2 == 0)
            {
                sumeven = sumeven + nums[i];
            }
        }
        vector<int>result;
        int q = queries.size();
        for(int i=0;i<q;i++)
        {
            int val = queries[i][0];
            int index = queries[i][1];
            if(nums[index] % 2 == 0)
            {
                sumeven = sumeven - nums[index];
            }
            nums[index] = nums[index] + val;
            if(nums[index] % 2 == 0)
            {
                sumeven = sumeven + nums[index];
            }
            result.push_back(sumeven);
        }
        return result;
    }
};