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
    int tabu(int n, vector<int>& nums, vector<vector<int>>& dp)
    {
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i-1;j>=-1;j--)
            {
                int not_take = dp[i+1][j+1];
                int take = INT_MIN;
                if(j == -1 || nums[j] < nums[i])
                {
                    take = 1 + dp[i+1][i+1];
                }
                dp[i][j+1] = max(not_take,take);
            }
        }
        return dp[0][0];
    }
    int space(int n, vector<int>& nums, vector<int>& dp)
    {
        for(int i=n-1;i>=0;i--)
        {
            vector<int>temp(n+1,0);
            for(int j=i-1;j>=-1;j--)
            {
                int not_take = dp[j+1];
                int take = INT_MIN;
                if(j == -1 || nums[j] < nums[i])
                {
                    take = 1 + dp[i+1];
                }
                temp[j+1] = max(not_take,take);
            }
            dp = temp;
        }
        return dp[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return memo(0,-1,nums,dp);

        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return tabu(n,nums,dp);

        vector<int>dp(n+1,0);
        return space(n,nums,dp);
    }
};