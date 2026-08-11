class Solution {
public:
    bool recur(int n)
    {
        if(n == 0)
        {
            return false;
        }
        for(int i=1;i*i<=n;i++)
        {
            if(recur(n - (i*i)) == false)
            {
                return true;
            }
        }
        return false;
    }
    bool memo(int n, vector<int>& dp)
    {
        if(n == 0)
        {
            return false;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        for(int i=1;i*i<=n;i++)
        {
            if(memo(n - (i*i), dp) == false)
            {
                dp[n] = true;
                return dp[n];
            }
        }
        dp[n] = false;
        return dp[n];
    }
    bool winnerSquareGame(int n) {
        // return recur(n);
        vector<int>dp(n+1,-1);
        return memo(n,dp);
    }
};