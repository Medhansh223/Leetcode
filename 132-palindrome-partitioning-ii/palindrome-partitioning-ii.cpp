class Solution {
public:
    bool isPalindrome(int i, int j, string& s)
    {
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int memo(int i, int j, string& s, vector<int>& dp)
    {
        if(i >= j || isPalindrome(i,j,s)) 
        {
            return 0;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        int mini = INT_MAX;
        for(int k=i;k<j;k++)
        {
            if(isPalindrome(i,k,s) == true)
            {
                int cost = 1 + memo(k+1,j,s,dp);
                mini = min(mini,cost);
            }
        }
        dp[i] = mini;
        return dp[i];
    }
    int minCut(string s) {
        int n = s.length();
        vector<int>dp(n+1,-1);   
        return memo(0,n-1,s,dp);
    }
};