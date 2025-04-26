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
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return memo(0,1,2,dp,prices);
    }
};