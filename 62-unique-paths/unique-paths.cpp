class Solution {
public:
    int memoization(int i, int j, vector<vector<int>>& dp)
    {
        if(i==0 && j==0)
        {
            return 1;
        }
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int up=memoization(i-1,j,dp);
        int left=memoization(i,j-1,dp);
        dp[i][j]=up+left;
        return dp[i][j];
    }

    int optimization(int m, int n, vector<int>& prev)
    {
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,-1);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    temp[j]=1;
                }
                else
                {
                    int up=0;
                    int left=0;
                    if(i>0)
                    {
                        up=prev[j];
                    }
                    if(j>0)
                    {
                        left=temp[j-1];
                    }
                    temp[j]=up+left;
                }
            }
            prev=temp;
        }
        return prev[n-1];
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // int ans1 = memoization(m-1,n-1,dp);
        // int ans2 = tabulation(m,n,dp);
        vector<int>dp(n,-1);
        int ans3 = optimization(m,n,dp);
        return ans3;
    }
};