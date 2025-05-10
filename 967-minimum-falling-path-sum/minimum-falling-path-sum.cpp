class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        if(j < 0 || j >= n)
        {
            return 1e9;
        }
        if(i == 0)
        {
            return matrix[i][j];
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int up = matrix[i][j] + memo(i-1,j,dp,matrix);
        int ld = matrix[i][j] + memo(i-1,j-1,dp,matrix);
        int rd = matrix[i][j] + memo(i-1,j+1,dp,matrix);
        dp[i][j] = min({up,ld,rd});
        return dp[i][j];
    }
    int tabu(int n, vector<vector<int>>& dp, vector<vector<int>>& matrix)
    {
        for(int i=0;i<n;i++)
        {
            dp[0][i] = matrix[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int ld = matrix[i][j];
                if(j-1 >= 0)
                {
                    ld = ld + dp[i-1][j-1];
                }
                else
                {
                    ld = ld + 1e9;
                }
                int up = matrix[i][j] + dp[i-1][j];
                int rd = matrix[i][j];
                if(j+1 < n)
                {
                    rd = rd + dp[i-1][j+1];
                }
                else
                {
                    rd = rd + 1e9;
                }
                dp[i][j] = min(ld,min(up,rd));
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
    int space(int n, vector<int>& prev, vector<vector<int>>& matrix)
    {   
        for(int i=0;i<n;i++)
        {
            prev[i] = matrix[0][i];
        }
        for(int i=1;i<n;i++)
        {
            vector<int>temp(n,-1);
            for(int j=0;j<n;j++)
            {
                int ld = matrix[i][j];
                if(j-1 >= 0)
                {
                    ld = ld + prev[j-1];
                }
                else
                {
                    ld = ld + 1e9;
                }
                int up = matrix[i][j] + prev[j];
                int rd = matrix[i][j];
                if(j+1 < n)
                {
                    rd = rd + prev[j+1];
                }
                else
                {
                    rd = rd + 1e9;
                }
                temp[j] = min(ld,min(up,rd));
            }
            prev = temp;
        }
        return *min_element(prev.begin(),prev.end());
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // int ans = 1e9;
        // for(int i=0;i<n;i++)
        // {
        //     ans = min(ans,memo(n-1,i,dp,matrix));
        // }
        // return ans;
        // return tabu(n,dp,matrix);
        vector<int>dp(n,-1);
        return space(n,dp,matrix);
    }
};