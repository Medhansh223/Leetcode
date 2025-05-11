class Solution {
public:
    int memo(int i, int amount, vector<vector<int>>& dp, vector<int>& coins)
    {
        if(i == 0)
        {
            if(amount % coins[i] == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[i][amount] != -1)
        {
            return dp[i][amount];
        }
        int not_pick = memo(i-1,amount,dp,coins);
        int pick = 0;
        if(coins[i] <= amount)
        {
            pick = memo(i,amount - coins[i],dp,coins);
        }
        dp[i][amount] = pick + not_pick;
        return dp[i][amount];
    }
    int tabu(int n, int amount, vector<vector<long long>>& dp, vector<int>& coins)
    {
        for(int i=0;i<=amount;i++)
        {
            if(i % coins[0] == 0)
            {
                dp[0][i] = 1;
            }
            else
            {
                dp[0][i] = 0;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                long long not_pick = dp[i-1][j];
                long long pick = 0;
                if(coins[i] <= j)
                {
                    pick = dp[i][j - coins[i]];
                }
                dp[i][j] = (int)pick + not_pick;
            }
        }
        return (int)dp[n-1][amount];
    }
    int space(int n, int amount, vector<int>& dp, vector<int>& coins)
    {
        for(int i=0;i<=amount;i++)
        {
            if(i % coins[0] == 0)
            {
                dp[i] = 1;
            }
            else
            {
                dp[i] = 0;
            }
        }
        for(int i=1;i<n;i++)
        {
            vector<int>temp(amount+1,0);
            for(int j=0;j<=amount;j++)
            {
                int not_pick = dp[j];
                int pick = 0;
                if(coins[i] <= j)
                {
                    pick = temp[j - coins[i]];
                }
                temp[j] = pick + not_pick;
            }
            dp = temp;
        }
        return dp[amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // return memo(n-1,amount,dp,coins);

        vector<vector<long long>>dp(n,vector<long long>(amount+1,0));
        return tabu(n,amount,dp,coins);

        // vector<int>dp(amount+1,0);
        // int ans = space(n,amount,dp,coins);
    }
};