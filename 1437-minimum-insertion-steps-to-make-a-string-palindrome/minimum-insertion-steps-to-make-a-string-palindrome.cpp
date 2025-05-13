class Solution {
public:
    int memo(int i, int j, string s, string t, vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        } 
        if(s[i] == t[j])
        {
            return 1 + memo(i-1,j-1,s,t,dp);
        }
        int left = memo(i,j-1,s,t,dp);
        int top = memo(i-1,j,s,t,dp);
        dp[i][j] = max(left,top);
        return dp[i][j];
    }
    int tabu(int n, int m, string s, string t, vector<vector<int>>& dp)
    {
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
        }
        for(int j=0;j<=n;j++)
        {
            dp[j][0] = 0;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    int left = dp[i][j-1];
                    int top = dp[i-1][j];
                    dp[i][j] = max(left,top);
                }
            }
        }
        return dp[n][m];
    }
    int space(int n, int m, string s, string t, vector<int>& dp)
    {
        for(int i=0;i<=m;i++)
        {
            dp[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            vector<int>temp(m+1,-1);
            temp[0] = 0;
            for(int j=1;j<=n;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    temp[j] = 1 + dp[j-1];
                }
                else
                {
                    int left =temp[j-1];
                    int top = dp[j];
                    temp[j] = max(left,top);
                }
            }
            dp = temp;
        }
        return dp[m];
    }
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        int m = t.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return n - memo(n-1,m-1,s,t,dp);

        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return n - tabu(n,m,s,t,dp);

        vector<int>dp(m+1,-1);
        return n - space(n,m,s,t,dp);
    }
};