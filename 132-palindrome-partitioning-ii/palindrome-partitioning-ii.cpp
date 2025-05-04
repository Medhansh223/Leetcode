class Solution {
public:
        bool isPalindrome (string & s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    // int memo(int i, int n, string s, vector<int>& dp)
    // {
    //     if(i == n)
    //     {
    //         return 0;
    //     }
    //     if(dp[i] != -1)
    //     {
    //         return dp[i];
    //     }
    //     int mini = INT_MAX;
    //     for(int j=i;j<n;j++)
    //     {
    //         if(isPalindrome(i,j,s) == true)
    //         {
    //             int cost = 1 + memo(j+1,n,s,dp);
    //             mini = min(mini,cost);
    //         }
    //     }
    //     dp[i] = mini;
    //     return dp[i];
    // }
    int solve (string & s, int i, int j, vector<int> & dp){    
        
        if(i>=j or isPalindrome(s, i, j)) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int ans = INT_MAX;
        
        for(int k=i; k<j; k++){
            
            if(isPalindrome(s, i, k)){                         
                int temp = solve (s, k+1, j, dp) + 1;
                ans = min (ans, temp);
            }
        }
        
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.length();
        
        /* I've used 1D DP here becoz only one parameter is changing i.e. `i` */
        
        vector<int> dp (n+1, -1);   
            
        return solve (s, 0, n-1, dp);
    }
};