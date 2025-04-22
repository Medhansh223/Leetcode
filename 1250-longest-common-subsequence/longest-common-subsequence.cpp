class Solution {
public:
    int memo(int i,int j, vector<vector<int>>&dp,string text1,string text2)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(text1[i]==text2[j])
        {
            return 1+memo(i-1,j-1,dp,text1,text2);
        }
        int up=memo(i-1,j,dp,text1,text2);
        int left=memo(i,j-1,dp,text1,text2);
        dp[i][j]=max(up,left);
        return dp[i][j];
    }
    int tabu(int n,int m,vector<vector<int>>&dp,string text1,string text2)
    {
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
        }
        for(int j=0;j<=n;j++)
        {
            dp[j][0]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    int up=dp[i-1][j];
                    int left=dp[i][j-1];
                    dp[i][j]=max(up,left);
                }
            }
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return memo(n-1,m-1,dp,text1,text2);

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return tabu(n,m,dp,text1,text2);
    }
};