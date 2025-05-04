class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& dp, vector<int>& cuts)
    {
        if(i > j)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int ind=i;ind<=j;ind++)
        {
            int len = cuts[j+1] - cuts[i-1] + memo(i,ind-1,dp,cuts) + memo(ind+1,j,dp,cuts);
            mini = min(mini,len);
        }
        dp[i][j] = mini;
        return dp[i][j];
    }
    int tabu(int c, vector<vector<int>>& dp, vector<int>& cuts)
    {
        for(int i=c;i>=1;i--)
        {
            for(int j=1;j<=c;j++)
            {
                if(i > j)
                {
                    continue;
                }
                int mini = INT_MAX;
                for(int ind=i;ind<=j;ind++)
                {
                    int length = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    mini = min(mini,length);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        // vector<vector<int>>dp(c+2,vector<int>(c+2,-1));
        // return memo(1,c,dp,cuts);
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        return tabu(c,dp,cuts);
    }
};