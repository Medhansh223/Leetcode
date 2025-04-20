class Solution {
public:
    int memo(int i,int amount,vector<vector<int>>&dp,vector<int>&coins)
    {
        if(i==0)
        {
            if(amount%coins[0]==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }
        int nonpick=memo(i-1,amount,dp,coins);
        int pick=0;
        if(coins[i]<=amount)
        {
            pick=memo(i,amount-coins[i],dp,coins);
        }
        dp[i][amount]=pick+nonpick;
        return dp[i][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return memo(n-1,amount,dp,coins);
    }
};