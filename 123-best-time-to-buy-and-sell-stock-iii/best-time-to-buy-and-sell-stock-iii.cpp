class Solution {
public:
    int memo(int i,int buy, int cap,vector<vector<vector<int>>>&dp,vector<int>&prices)
    {
        int n=prices.size();
        if(i==n || cap==0)
        {
            return 0;
        }
        if(dp[i][buy][cap]!=-1)
        {
            return dp[i][buy][cap];
        }
        int profit=INT_MIN;
        if(buy==1)
        {
            profit=max(-prices[i]+memo(i+1,0,cap,dp,prices),memo(i+1,1,cap,dp,prices));
        }
        else
        {
            profit=max(prices[i]+memo(i+1,1,cap-1,dp,prices),memo(i+1,0,cap,dp,prices));
        }
        return dp[i][buy][cap]=profit;
    }
    int tabu(int n,vector<vector<vector<int>>>&dp,vector<int>&prices)
    {
        for(int i=0;i<n;i++)//cap=0
        {
            for(int j=0;j<2;j++)
            {
                dp[i][j][0]=0;
            }
        }
        for(int i=0;i<2;i++)//last day array end return nothing buy and sell 
        {
            for(int j=0;j<3;j++)
            {
                dp[n][i][j]=0;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=1;k<3;k++)
                {
                    int profit=INT_MIN;
                    if(j==1)
                    {
                        profit=max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    }
                    else
                    {
                        profit=max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                    }
                    dp[i][j][k]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return memo(0,1,2,dp,prices);
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return tabu(n,dp,prices);
    }
};