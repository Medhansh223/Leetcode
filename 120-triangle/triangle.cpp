class Solution {
public:
    int memoization(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& triangle)
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
        int down = triangle[i][j] + memoization(i+1,j,dp,triangle);
        int dg = triangle[i][j] + memoization(i+1,j+1,dp,triangle);
        dp[i][j] = min(down,dg);
        return dp[i][j];
    }

    int tabulation(vector<vector<int>>& dp, vector<vector<int>>& triangle)
    {
        int n=triangle.size();
        for(int i=0;i<n;i++)
        {
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,dg);
            }
        }
        return dp[0][0];
    }

    int optimisation( vector<int>& prev, vector<vector<int>>& triangle)
    {
        int n=triangle.size();
        for(int j=0;j<n;j++)
        {
            prev[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            vector<int>curr(n,-1);
            for(int j=i;j>=0;j--)
            {
                int down = triangle[i][j] + prev[j];
                int dg = triangle[i][j] + prev[j+1];
                curr[j] = min(down,dg);
            }
            prev=curr;
        }
        return prev[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // int ans1 = memoization(0,0,dp,triangle);
        // int ans2 = tabulation(dp,triangle);
        vector<int>dp(n,-1);
        int ans3 = optimisation(dp,triangle);
        return ans3;
    }
};