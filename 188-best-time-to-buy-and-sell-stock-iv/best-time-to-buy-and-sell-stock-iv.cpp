class Solution {
public:
    int memo(int day, int task, int cap, vector<vector<vector<int>>>& dp, vector<int>& prices)
    {
        int n = prices.size();
        if(day == n || cap == 0)
        {
            return 0;
        }    
        if(dp[day][task][cap] != -1)
        {
            return dp[day][task][cap]; 
        }
        int profit = INT_MIN;
        if(task == 0)
        {
            profit = max(-prices[day] + memo(day+1,1,cap,dp,prices), memo(day+1,0,cap,dp,prices));
        }
        else if(task == 1)
        {
            profit = max(prices[day] + memo(day+1,0,cap-1,dp,prices), memo(day+1,1,cap,dp,prices));
        }
        return dp[day][task][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return memo(0,0,k,dp,prices);
    }
};