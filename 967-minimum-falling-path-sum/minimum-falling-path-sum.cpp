class Solution {
public:
    int memoization(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        if(j<0 || j>=m)
        {
            return 1e9;
        }
        if(i==0)
        {
            return matrix[0][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ld = matrix[i][j] + memoization(i-1,j-1,dp,matrix);
        int up = matrix[i][j] + memoization(i-1,j,dp,matrix);
        int rd = matrix[i][j] + memoization(i-1,j+1,dp,matrix);
        dp[i][j]=min(ld,min(up,rd));
        return dp[i][j];
    }

    int tabulation(int n, int m, vector<vector<int>>& dp, vector<vector<int>>& matrix)
    {
        for(int j=0;j<m;j++)
        {
            dp[0][j] = matrix[0][j];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ld = matrix[i][j];
                if((j-1)>=0)
                {
                    ld = ld + dp[i-1][j-1];
                }
                else 
                {
                    ld = ld + 1e9;
                }
                int up = matrix[i][j] + dp[i-1][j];
                int rd = matrix[i][j];
                if((j+1)<m)
                {
                    rd = rd + dp[i-1][j+1];
                }
                else 
                {
                    rd = rd + 1e9;
                }
                dp[i][j]=min(ld,min(up,rd));
            }
        }
        int ans = 1e9;
        for(int j=0;j<m;j++)
        {
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }

    int optimisation(vector<int>& prev, vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int j=0;j<m;j++)
        {
            prev[j] = matrix[0][j];
        }
        for(int i=1;i<n;i++)
        {
            vector<int>temp(m,-1);
            for(int j=0;j<m;j++)
            {
                int ld = matrix[i][j];
                if((j-1)>=0)
                {
                    ld = ld + prev[j-1];
                }
                else 
                {
                    ld = ld + 1e9;
                }
                int up = matrix[i][j] + prev[j];
                int rd = matrix[i][j];
                if((j+1)<m)
                {
                    rd = rd + prev[j+1];
                }
                else 
                {
                    rd = rd + 1e9;
                }
                temp[j]=min(ld,min(up,rd));
            }
            prev = temp;
        }
        int ans = 1e9;
        for(int j=0;j<m;j++)
        {
            ans=min(ans,prev[j]);
        }
        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // int ans1 = 1e9;
        // for(int j=0;j<m;j++)
        // {
        //     ans1 = min(ans1,memoization(n-1,j,dp,matrix));
        // }
        // int ans2 = tabulation(n,m,dp,matrix);
        vector<int>prev(m,-1);
        int ans3 = optimisation(prev,matrix);
        return ans3;
    }
};