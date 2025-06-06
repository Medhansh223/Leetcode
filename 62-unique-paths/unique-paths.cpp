class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& dp)
    {
        if(i == 0 && j == 0)
        {
            return 1;
        }
        if(i < 0 || j < 0)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int left = memo(i,j-1,dp);
        int up = memo(i-1,j,dp);
        dp[i][j] = left + up;
        return dp[i][j];
    }
    int tabu(int m, int n, vector<vector<int>>& dp)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                int left = 0;
                if(j-1 >= 0)
                {
                    left = dp[i][j-1];
                }
                int up = 0;
                if(i-1 >= 0)
                {
                    up = dp[i-1][j];
                }
                dp[i][j] = left + up;
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return memo(m-1,n-1,dp);
        return tabu(m,n,dp);
    }
};