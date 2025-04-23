class Solution {
public:
    int memo(int i,int j,vector<vector<int>>&dp,string s1,string s2)
    {
        if(i<0||j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s1[i]==s2[j])
        {
            return 1+memo(i-1,j-1,dp,s1,s2);
        }
        int up=memo(i-1,j,dp,s1,s2);
        int left=memo(i,j-1,dp,s1,s2);
        return dp[i][j]=max(up,left);
    }
    int tabu(int n,int m,vector<vector<int>>&dp,string s1,string s2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
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
    int space(int n,int m,vector<int>&prev,string s1,string s2)
    {
        for(int i=1;i<=n;i++)
        {
            vector<int>temp(n+1,0);
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    temp[j]=1+prev[j-1];
                }
                else
                {
                    int up=prev[j];
                    int left=temp[j-1];
                    temp[j]=max(up,left);
                }
            }
            prev = temp;
        }
        return prev[m];
    }
    int minInsertions(string s) {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return n-memo(n-1,n-1,dp,s,rev);
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return n-tabu(n,n,dp,s,rev);
        vector<int>dp(n+1,0);
        return n - space(n,n,dp,s,rev);
    }
};