class Solution {
public:
    int recur(int i, int j)
    {
        if(i == 0 && j == 0)
        {
            return 1;
        }
        if(i < 0 || j < 0)
        {
            return 0;
        }
        int left = recur(i,j-1);
        int up = recur(i-1,j);
        return left + up;
    }
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
        return dp[i][j] = left + up;
    }
    int uniquePaths(int m, int n) {
        // return recur(m-1,n-1);
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return memo(m-1,n-1,dp);
    }
};