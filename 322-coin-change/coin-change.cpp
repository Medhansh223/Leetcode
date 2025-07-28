class Solution {
public:
    int memo(int ind,vector<vector<int>>&dp,vector<int>&coins,int amount)
    {
        if(ind==0)
        {
            if(amount%coins[0]==0)
            {
                return amount/coins[0];
            }
            else
            {
                return 1e9;
            }
        }
        if(dp[ind][amount]!=-1)
        {
            return dp[ind][amount];
        }
        int nonpick=memo(ind-1,dp,coins,amount);
        int pick=1e9;
        if(coins[ind]<=amount)
        {
            pick=memo(ind,dp,coins,amount-coins[ind])+1;
        }
        return dp[ind][amount]=min(pick,nonpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=memo(n-1,dp,coins,amount);
        if(ans==1e9)
        {
            return -1;
        }
        return ans;
    }
};