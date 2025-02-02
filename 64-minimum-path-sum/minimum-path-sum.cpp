class Solution {
public:
    int memoization(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        if(i==0 && j==0)
        {
            return grid[i][j];
        }
        if(i<0 || j<0)
        {
            return 1e9;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int left = grid[i][j] + memoization(i,j-1,dp,grid);
        int up = grid[i][j] + memoization(i-1,j,dp,grid);
        dp[i][j]=min(left,up);
        return dp[i][j];
    }

    int tabulation(int n, int m, vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                }
                else
                {
                    int up=grid[i][j];
                    if(i>0)
                    {
                        up=up+dp[i-1][j];
                    }
                    else
                    {
                        up=up+1e9;
                    }
                    int left=grid[i][j];
                    if(j>0)
                    {
                        left=left+dp[i][j-1];
                    }
                    else
                    {
                        left=left+1e9;
                    }
                    dp[i][j]=min(left,up);
                }
            }
        }
        return dp[n-1][m-1];
    }

    int optimisation(int n, int m, vector<int>& prev, vector<vector<int>>& grid)
    {
        for(int i=0;i<n;i++)
        {
            vector<int>temp(m,-1);
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    temp[j]=grid[i][j];
                }
                else
                {
                    int up=grid[i][j];
                    if(i>0)
                    {
                        up=up+prev[j];
                    }
                    else
                    {
                        up=up+1e9;
                    }
                    int left=grid[i][j];
                    if(j>0)
                    {
                        left=left+temp[j-1];
                    }
                    else
                    {
                        left=left+1e9;
                    }
                    temp[j]=min(left,up);
                }
            }
            prev=temp;
        }
        return prev[m-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // int ans1 = memoization(n-1, m-1, dp, grid);
        // int ans2 = tabulation(n,m,dp,grid);
        vector<int>dp(m,-1);
        int ans3 = optimisation(n,m,dp,grid);
        return ans3;
    }
};