class Solution {
public:
    int memo(int i,int day, vector<vector<int>>&dp,vector<int>&prices)
    {
        int n=prices.size();
        if(i==n)
        {
            return 0;
        }
        if(dp[i][day]!=-1)
        {
            return dp[i][day];
        }
        int profit=0;
        if(day==1)
        {
            profit = max(-prices[i]+memo(i+1,0,dp,prices),memo(i+1,1,dp,prices));
        }
        else
        {
            profit=max(prices[i]+memo(i+1,1,dp,prices),memo(i+1,0,dp,prices));
        }
        dp[i][day]=profit;
        return dp[i][day];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return memo(0,1,dp,prices);
    }
};
//1-->buy
//0-->sell (not buy)