class Solution {
public:
    int memo(int i, int j, vector<int>& prices, vector<vector<int>>& dp)
    {
        int n = prices.size();
        if(i == n || j == 2)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int maxi = INT_MIN;
        if(j == 0)
        {
            maxi = max(-prices[i] + memo(i+1,1,prices,dp), memo(i+1,0,prices,dp));
        }
        else if(j == 1)
        {
            maxi = max(prices[i] + memo(i+1,2,prices,dp), memo(i+1,1,prices,dp));
        }
        return dp[i][j] = maxi;
    }
    int tabu(int n, vector<int>& prices, vector<vector<int>>& dp)
    {
        dp[n][0] = dp[n][1] = dp[n][2] = 0;
        for(int i=0;i<n;i++)
        {
            dp[i][2] = 0;
        }
        int maxi = INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                if(j == 0)
                {
                    maxi = max(-prices[i] + dp[i+1][1], dp[i+1][0]);
                }
                else if(j == 1)
                {
                    maxi = max(prices[i] + dp[i+1][2], dp[i+1][1]);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[0][0];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>>dp(prices.size(),vector<int>(3,-1));
        // return memo(0,0,prices,dp);
        vector<vector<int>>dp(prices.size()+1,vector<int>(3,-1));
        return tabu(n,prices,dp);
    }
};