class Solution {
public:
    int memo(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&triangle)
    {
        int n=triangle.size();
        if(i==n-1)
        {
            return triangle[n-1][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int down=triangle[i][j] + memo(i+1,j,dp,triangle);
        int dj=triangle[i][j] + memo(i+1,j+1,dp,triangle);
        dp[i][j]=min(down,dj);
        return dp[i][j];
    }
    int tabu(vector<vector<int>>&dp,vector<vector<int>>&triangle)
    {
        int n=triangle.size();
        dp[0][0]=triangle[0][0];
        int mini=INT_MAX;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                int up = INT_MAX, ld = INT_MAX;

                if (j < i) up = triangle[i][j] + dp[i - 1][j]; // from directly above
                if (j > 0) ld = triangle[i][j] + dp[i - 1][j - 1]; // from left diagonal);
                dp[i][j]=min(up,ld);
            }
        }
        // return *min_element(dp[n - 1].begin(), dp[n - 1].begin() + n);
        int s=dp[n-1].size();
        for(int i=0;i<s;i++)
        {   
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
    }
    int space(vector<int>& prev, vector<vector<int>>& triangle)
    {
        prev[0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++)
        {
            vector<int>temp(triangle.size(),-1);
            for(int j=0;j<=i;j++)
            {
                int up = INT_MAX;
                int ld = INT_MAX;
                if(j<i)
                {
                    up = triangle[i][j] + prev[j];
                }
                if(j>0)
                {
                    ld = triangle[i][j] + prev[j-1];
                }
                temp[j] = min(up,ld);
            }
            prev = temp;
        }
        return *min_element(prev.begin(),prev.end());
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return memo(0,0,dp,triangle);
        // return tabu(dp,triangle);
        vector<int>dp(n,-1);
        return space(dp,triangle);
    }
};