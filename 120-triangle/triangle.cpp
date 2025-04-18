class Solution {
public:
    int memo(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&triangle)
    {
        int n=triangle.size();
        if(i==n-1)
        {
            return triangle[n-1][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int down=triangle[i][j] + memo(i+1,j,dp,triangle);
        int dj=triangle[i][j] + memo(i+1,j+1,dp,triangle);
        dp[i][j]=min(down,dj);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return memo(0,0,dp,triangle);
    }
};