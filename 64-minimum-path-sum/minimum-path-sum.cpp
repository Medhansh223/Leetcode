class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        if(i==0 && j==0)
        {
            return grid[i][j];
        }
        if(i<0 || j<0)
        {
            return 1e9;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int up = grid[i][j] + memo(i-1,j,dp,grid);
        int left = grid[i][j] + memo(i,j-1,dp,grid);
        dp[i][j] = min(up,left);
        return dp[i][j];
    }
    int tabu(int n, int m, vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j] = grid[i][j];
                }
                else
                {
                    int up = grid[i][j];
                    if(i > 0)
                    {
                        up = up + dp[i-1][j];
                    }
                    else
                    {
                        up = up + 1e9;
                    }
                    int left = grid[i][j];
                    if(j > 0)
                    {
                        left = left + dp[i][j-1];
                    }
                    else
                    {
                        left = left + 1e9;
                    } 
                    dp[i][j] = min(left,up);
                }
            }
        }
        return dp[n-1][m-1];
    }
    int space(int n, int m, vector<int>& dp, vector<vector<int>>& grid)
    {
        for(int i=0;i<n;i++)
        {
            vector<int>temp(m,-1);
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    temp[j] = grid[i][j];
                }
                else
                {
                    int up = grid[i][j];
                    if(i >= 1)
                    {
                        up = up + dp[j];
                    }
                    else
                    {
                        up = up + 1e9;
                    }
                    int left = grid[i][j];
                    if(j >= 1)
                    {
                        left = left + temp[j-1];
                    }
                    else
                    {
                        left = left + 1e9;
                    } 
                    temp[j] = min(left,up);
                }
            }
            dp = temp;
        }
        return dp[m-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return memo(n-1,m-1,dp,grid);
        // return tabu(n,m,dp,grid);
        vector<int>dp(m,-1);
        return space(n,m,dp,grid);
    }
};