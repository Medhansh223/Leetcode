class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        int sum=0;
        vector<int>result;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                sum=sum+nums[i];
            }
        }
        for(int i=0;i<q;i++)
        {
            int val=queries[i][0];
            int ind=queries[i][1];
            if(nums[ind]%2==0)
            {
                sum=sum-nums[ind];
            }
            nums[ind]=nums[ind]+val;
            if(nums[ind]%2==0)
            {
                sum=sum+nums[ind];
            }
            result.push_back(sum);
        }
        return result;
    }
};