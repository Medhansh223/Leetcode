class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& dp, string word1, string word2)
    {
        if(i < 0)
        {
            return j+1;
        }
        if(j < 0)
        {
            return i+1;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(word1[i] == word2[j])
        {
            return memo(i-1,j-1,dp,word1,word2);
        }
        int insert = memo(i,j-1,dp,word1,word2);
        int del = memo(i-1,j,dp,word1,word2);
        int replace = memo(i-1,j-1,dp,word1,word2);
        dp[i][j] = 1 + min({insert,del,replace});
        return dp[i][j];
    }
    int tabu(int n, int m, vector<vector<int>>& dp, string word1, string word2)
    {
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = i;
        }
        for(int j=0;j<=m;j++)
        {
            dp[0][j] = j;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    int insert = dp[i][j-1];
                    int del = dp[i-1][j];
                    int replace = dp[i-1][j-1];
                    dp[i][j] = 1 + min({insert,del,replace});
                }
            }
        }
        return dp[n][m];
    }
    int space(int n, int m, vector<int>& prev, string word1, string word2)
    {
        for(int j=0;j<=m;j++)
        {
            prev[j] = j;
        }
        for(int i=1;i<=n;i++)
        {
            vector<int>temp(m+1,-1);
            temp[0] = i;
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    temp[j] = prev[j-1];
                }
                else
                {
                    int insert = temp[j-1];
                    int del = prev[j];
                    int replace = prev[j-1];
                    temp[j] = 1 + min({insert,del,replace});
                }
            }
            prev = temp;
        }
        return prev[m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return memo(n-1,m-1,dp,word1,word2);

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return tabu(n,m,dp,word1,word2);

        // vector<int>dp(m+1,-1);
        // return space(n,m,dp,word1,word2);
    }
};