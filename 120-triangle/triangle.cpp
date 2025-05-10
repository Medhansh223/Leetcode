class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& triangle)
    {
        int n = triangle.size();
        if(i == n-1)
        {
            return triangle[n-1][j];
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int down = triangle[i][j] + memo(i+1,j,dp,triangle);
        int dj = triangle[i][j] + memo(i+1,j+1,dp,triangle);
        dp[i][j] = min(down,dj);
        return dp[i][j];
    }
    int tabu(int n, vector<vector<int>>& dp, vector<vector<int>>& triangle)
    {
        for(int i=0;i<n;i++)
        {
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int dj = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,dj);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        // return memo(0,0,dp,triangle);
        return tabu(n,dp,triangle);
    }
};