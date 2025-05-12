class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& dp, string s, string t)
    {
        if(i < 0 || j < 0)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            dp[i][j];
        }
        if(s[i] == t[j])
        {
            return 1 + memo(i-1,j-1,dp,s,t);
        }
        int left = memo(i,j-1,dp,s,t);
        int up = memo(i-1,j,dp,s,t);
        dp[i][j] = max(left,up);
        return dp[i][j];
    }
    int tabu(int n, int m, vector<vector<int>>& dp, string s, string t)
    {
        for(int i=0;i<=m;i++)
        {
            dp[0][i] = 0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    int left = dp[i][j-1];
                    int up = dp[i-1][j];
                    dp[i][j] = max(left,up);
                }
            }
        }
        return dp[n][m];
    }
    int space(int n, int m, vector<int>& prev, string s, string t)
    {
        for(int i=0;i<=m;i++)
        {
            prev[i] = 0;
        }
        for(int i=1;i<=n;i++)
        {
            vector<int>temp(m+1,-1);
            temp[0] = 0;
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    temp[j] = 1 + prev[j-1];
                }
                else
                {
                    int left = temp[j-1];
                    int up = prev[j];
                    temp[j] = max(left,up);
                }
            }
            prev = temp;
        }
        return prev[m];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        int m = t.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return memo(n-1,m-1,dp,s,t);

        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return tabu(n,m,dp,s,t);

        vector<int>dp(m+1,-1);
        return space(n,m,dp,s,t);
    }
};