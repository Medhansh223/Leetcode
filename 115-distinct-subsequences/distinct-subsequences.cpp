class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& dp, string s, string t)
    {
        if(j < 0)
        {
            return 1;
        }
        if(i < 0)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(s[i] == t[j])
        {
            return memo(i-1,j-1,dp,s,t) + memo(i-1,j,dp,s,t);
        }
        dp[i][j] = memo(i-1,j,dp,s,t);
        return dp[i][j];
    }
    int tabu(int n, int m, vector<vector<double>>& dp, string s, string t)
    {
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 1;
        }
        for(int i=1;i<=m;i++)
        {
            dp[0][i] = 0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
    int space(int n, int m, vector<double>& prev, string s, string t)
    {
        prev[0] = 1;
        for(int i=1;i<=m;i++)
        {
            prev[i] = 0;
        }
        for(int i=1;i<=n;i++)
        {
            vector<double>temp(m+1,-1);
            temp[0] = 1;
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    temp[j] = prev[j-1] + prev[j];
                }
                else
                {
                    temp[j] = prev[j];
                }
            }
            prev = temp;
        }
        return (int)prev[m];
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return memo(n-1,m-1,dp,s,t);

        // vector<vector<double>>dp(n+1,vector<double>(m+1,-1));
        // return tabu(n,m,dp,s,t);

        vector<double>dp(m+1,-1);
        return space(n,m,dp,s,t);
    }
};