class Solution {
public:
    int memo(int i, int amount, vector<vector<int>>& dp, vector<int>& coins)
    {
        if(i == 0)
        {
            if(amount % coins[i] == 0)
            {
                return amount / coins[i];
            }
            else
            {
                return 1e9;
            }
        }
        if(dp[i][amount] != -1)
        {
            return dp[i][amount];
        }
        int not_pick = memo(i-1,amount,dp,coins);
        int pick = INT_MAX;
        if(coins[i] <= amount)
        {
            pick = 1 + memo(i,amount - coins[i],dp,coins);
        }
        dp[i][amount] = min(pick,not_pick);
        return dp[i][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = memo(n-1,amount,dp,coins);
        if(ans == 1e9)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};