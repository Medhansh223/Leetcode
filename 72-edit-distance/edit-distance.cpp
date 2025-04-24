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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return memo(n-1,m-1,dp,word1,word2);
    }
};