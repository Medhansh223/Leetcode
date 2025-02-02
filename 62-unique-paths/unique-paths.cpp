class Solution {
public:
    int memoization(int i, int j, vector<vector<int>>& dp)
    {
        if(i==0 && j==0)
        {
            return 1;
        }
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int up=memoization(i-1,j,dp);
        int left=memoization(i,j-1,dp);
        dp[i][j]=up+left;
        return dp[i][j];
    }

    int tabulation(int m, int n, vector<vector<int>>& dp)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    int up=0;
                    int left=0;
                    if(i>0)
                    {
                        up=dp[i-1][j];
                    }
                    if(j>0)
                    {
                        left=dp[i][j-1];
                    }
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // int ans1 = memoization(m-1,n-1,dp);
        int ans2 = tabulation(m,n,dp);
        return ans2;
    }
};