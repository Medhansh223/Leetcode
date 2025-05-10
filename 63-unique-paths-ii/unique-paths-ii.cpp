class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid)
    {
        if(i >=0 && j>=0 && obstacleGrid[i][j] == 1)
        {
            return 0;
        }
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
        int left = memo(i,j-1,dp,obstacleGrid);
        int up = memo(i-1,j,dp,obstacleGrid);
        dp[i][j] = left + up;
        return dp[i][j];
    }
    int tabu(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=0 && j>=0 && obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                }
                else if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
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
        }
        return dp[m-1][n-1];
    }
    int space(int m, int n, vector<int>& dp, vector<vector<int>>& obstacleGrid)
    {
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,-1);
            for(int j=0;j<n;j++)
            {
                if(i>=0 && j>=0 && obstacleGrid[i][j]==1)
                {
                    temp[j]=0;
                }
                else if(i == 0 && j == 0)
                {
                    temp[j] = 1;
                }
                else
                {
                    int left = 0;
                    if(j-1 >= 0)
                    {
                        left = temp[j-1];
                    }
                    int up = 0;
                    if(i-1 >= 0)
                    {
                        up = dp[j];
                    }
                    temp[j] = left + up;
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return memo(m-1,n-1,dp,obstacleGrid);
        // return tabu(m,n,dp,obstacleGrid);
        vector<int>dp(n,-1);
        return space(m,n,dp,obstacleGrid);
    }
};