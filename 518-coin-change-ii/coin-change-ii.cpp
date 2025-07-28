class Solution {
public:
    int memo(int ind,vector<vector<int>>&dp,vector<int>&coins,int amount)
    {
        if(ind==0)
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
        if(dp[ind][amount]!=-1)
        {
            return dp[ind][amount];
        }
        int nonpick=memo(ind-1,dp,coins,amount);
        int pick=0;
        if(coins[ind]<=amount)
        {
            pick=memo(ind,dp,coins,amount-coins[ind]);
        }
        return dp[ind][amount]=(int)pick + nonpick;
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return memo(n-1,dp,coins,amount);
    }
};