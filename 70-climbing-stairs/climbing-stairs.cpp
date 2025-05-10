class Solution {
public:
    int memo(int i, vector<int>& dp)
    {
        if(i == 0 || i == 1)
        {
            return 1;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        int one_step = memo(i-1,dp);
        int two_step = memo(i-2,dp);
        dp[i] = one_step + two_step;
        return dp[i];

    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return memo(n,dp);
    }
};