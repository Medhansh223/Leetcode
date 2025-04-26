class Solution {
public:
    int memo(int i,int buy, vector<vector<int>>&dp,vector<int>&prices)
    {
        int n=prices.size();
        if(i==n)
        {
            return 0;
        }
        if(dp[i][buy]!=-1)
        {
            return dp[i][buy];
        }
        int profit=INT_MIN;
        if(buy==1)
        {
            profit=max(-prices[i]+memo(i+1,0,dp,prices),memo(i+1,1,dp,prices));
        }
        else
        {
            profit=max(prices[i]+memo(i+1,1,dp,prices),memo(i+1,0,dp,prices));
        }
        return dp[i][buy]=profit;
    }
    int tabu(int n,vector<vector<int>>&dp,vector<int>&prices)
    {
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                int profit=INT_MIN;
                if(j==1)
                {
                    profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else
                {
                    profit=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return memo(0,1,dp,prices);
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return tabu(n,dp,prices);
    }
};