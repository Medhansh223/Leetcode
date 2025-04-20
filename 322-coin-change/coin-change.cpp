class Solution {
public:
    int memo(int i,int amount, vector<vector<int>>&dp,vector<int>&coins)
    {
        if(i==0)
        {
            if(amount%coins[i]==0)
            {
                return amount/coins[i];
            }
            else
            {
                return 1e9;
            }
        }
        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }
        int nonpick=memo(i-1,amount,dp,coins);
        int pick=INT_MAX;
        if(coins[i]<=amount)
        {
            pick=1+memo(i,amount-coins[i],dp,coins);
        }
        dp[i][amount]=min(pick,nonpick);
        return dp[i][amount];
    }
    int tabu(int n,int amount, vector<vector<int>>&dp,vector<int>&coins)
    {
        for(int i=0;i<=amount;i++)
        {
            if(i % coins[0] == 0)
            {
                dp[0][i] = i/coins[0];
            }
            else
            {
                dp[0][i] = 1e9;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int nonpick = dp[i-1][j];
                int pick = 1e9;
                if(coins[i] <= j)
                {
                    pick = 1 + dp[i][j - coins[i]];
                }
                dp[i][j] = min(pick, nonpick);
            }
        }
        return dp[n-1][amount];
    }
    int space(int n,int amount,vector<int>&prev,vector<int>&coins)
    {
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            {
                prev[i]=i/coins[0];
            }
            else
            {
                prev[i]=1e9;
            }
        }
        for(int i=1;i<n;i++)
        {
            vector<int>temp(amount+1,0);
            for(int j=0;j<=amount;j++)
            {
                int nonpick=prev[j];
                int pick=1e9;
                if(coins[i]<=j)
                {
                    pick=1+temp[j-coins[i]];
                }
                temp[j]=min(pick,nonpick);
            }
            prev=temp;
        }
        return prev[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // int ans=memo(n-1,amount,dp,coins);

        // vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // int ans = tabu(n,amount,dp,coins);

        vector<int>dp(amount+1,0);
        int ans=space(n,amount,dp,coins);
        if(ans==1e9)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};