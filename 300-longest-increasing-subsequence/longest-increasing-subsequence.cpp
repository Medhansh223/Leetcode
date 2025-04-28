class Solution {
public:
    int memo(int i ,int prev, vector<int>& nums, vector<vector<int>>& dp)
    {
        int n = nums.size();
        if(i == n)
        {
            return 0;
        }
        if(dp[i][prev+1] != -1)
        {
            return dp[i][prev+1];
        }
        int not_take = 0 + memo(i+1,prev,nums,dp);
        int take = INT_MIN;
        if(prev == -1 || nums[i] > nums[prev])
        {
            take = 1 + memo(i+1,i,nums,dp);
        }
        dp[i][prev+1] = max(not_take,take);
        return dp[i][prev+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return memo(0,-1,nums,dp);
    }
};