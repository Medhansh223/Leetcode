class Solution {
public:
    int memo(int i, int prev, vector<vector<int>>& dp, vector<int>& nums)
    {
        if(i == nums.size())
        {
            return 0;
        }
        if(dp[i][prev+1] != -1)
        {
            return dp[i][prev+1];
        }
        int nottake = memo(i+1,prev,dp,nums);
        int take = INT_MIN;
        if(prev == -1 || nums[i] > nums[prev])
        {
            take = 1 + memo(i+1,i,dp,nums);
        }
        dp[i][prev+1] = max(take,nottake);
        return dp[i][prev+1];
    } 
    int tabu(int n, vector<vector<int>>& dp, vector<int>& nums)
    {
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j>=-1;j--)
            {
                int nottake = dp[i+1][j+1];
                int take = INT_MIN;
                if(j == -1 || nums[i] > nums[j])
                {
                    take = 1 + dp[i+1][i+1];
                }
                dp[i][j+1] = max(take,nottake);
            }
        }
        return dp[0][0];
    }
    int space(int n, vector<int>& dp, vector<int>& nums)
    {
        for(int i=n-1;i>=0;i--)
        {
            vector<int>temp(n+1,0);
            for(int j=i;j>=-1;j--)
            {
                int nottake = dp[j+1];
                int take = INT_MIN;
                if(j == -1 || nums[i] > nums[j])
                {
                    take = 1 + dp[i+1];
                }
                temp[j+1] = max(take,nottake);
            }
            dp = temp;
        }
        return dp[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return memo(0,-1,dp,nums);

        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return tabu(n,dp,nums);

        vector<int>dp(n+1,0);
        return space(n,dp,nums);
    }
};