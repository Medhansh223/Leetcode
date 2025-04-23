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
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = memo(n-1,m-1,dp,word1,word2);
        return (n-ans) + (m-ans);
    }
};