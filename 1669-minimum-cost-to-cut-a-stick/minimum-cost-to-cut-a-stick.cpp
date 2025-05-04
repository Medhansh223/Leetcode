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
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+2,vector<int>(c+2,-1));
        return memo(1,c,dp,cuts);
    }
};