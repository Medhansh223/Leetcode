class Solution {
public:
    int memoization(int n, vector<int>& dp)
    {
        if(n==0 || n==1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        dp[n]=memoization(n-1,dp)+memoization(n-2,dp);
        return dp[n];
    }

    int tabulation(int n, vector<int>& dp)
    {
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

    int optimization(int n)
    {
        if(n==0 || n==1)
        {
            return 1;
        }
        int prev1=1;
        int prev2=1;
        int curr;
        for(int i=2;i<=n;i++)
        {
            curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        // int ans1=memoization(n,dp);
        // int ans2=tabulation(n,dp);
        int ans3=optimization(n);
        return ans3;
    }
};