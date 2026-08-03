class Solution {
public:
    int recur(int i)
    {
        if(i == 0 || i == 1)
        {
            return 1;
        }
        int onestep = recur(i-1);
        int twostep = recur(i-2);
        return onestep+twostep;
    }
    int memo(vector<int>& dp, int i)
    {
        if(i == 0 || i == 1)
        {
            return 1;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        int onestep = memo(dp, i-1);
        int twostep = memo(dp, i-2);
        dp[i] = onestep+twostep;
        return dp[i];
    }
    int climbStairs(int n) {
        // return recur(n);
        vector<int>dp(n+1,-1);
        return memo(dp,n);
    }
};