class Solution {
public:
    int tabu(int n, int m, vector<vector<int>>& dp, vector<vector<int>>& matrix)
    {
        for(int i=0;i<m;i++)
        {
            dp[0][i] = matrix[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
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
                if(j+1 < m)
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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return tabu(n,m,dp,matrix);
    }
};