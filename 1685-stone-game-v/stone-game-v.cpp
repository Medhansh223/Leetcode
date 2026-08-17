class Solution {
public:
    int recur(int l, int r, vector<int>& prefixsum)
    {
        if(l >= r)
        {
            return 0;
        }
        int score = 0;
        for(int mid=l;mid<=r-1;mid++)
        {
            int leftsum = prefixsum[mid] - (l-1 >=0 ? prefixsum[l-1] : 0); 
            int rightsum = prefixsum[r] - prefixsum[mid];
            if(leftsum < rightsum)
            {
                score = max(score, leftsum + recur(l,mid,prefixsum)); 
            }
            else if(leftsum > rightsum)
            {
                score = max(score, rightsum + recur(mid+1,r,prefixsum));
            }
            else
            {
                score = max({score, leftsum + recur(l,mid,prefixsum), rightsum + recur(mid+1,r,prefixsum)});
            }
        }
        return score;
    }

    int memo(int l, int r, vector<int>& prefixsum, vector<vector<int>>& dp)
    {
        if(l >= r)
        {
            return 0;
        }
        if(dp[l][r] != -1)
        {
            return dp[l][r];
        }
        int score = 0;
        for(int mid=l;mid<=r-1;mid++)
        {
            int leftsum = prefixsum[mid] - (l-1 >=0 ? prefixsum[l-1] : 0); 
            int rightsum = prefixsum[r] - prefixsum[mid];
            if(leftsum < rightsum)
            {
                score = max(score, leftsum + memo(l,mid,prefixsum,dp)); 
            }
            else if(leftsum > rightsum)
            {
                score = max(score, rightsum + memo(mid+1,r,prefixsum,dp));
            }
            else
            {
                score = max({score, leftsum + memo(l,mid,prefixsum,dp), rightsum + memo(mid+1,r,prefixsum,dp)});
            }
        }
        dp[l][r] = score;
        return dp[l][r];
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>prefixsum(n+1,0);
        prefixsum[0] = stoneValue[0];
        for(int i=1;i<n;i++)
        {
            prefixsum[i] = stoneValue[i] + prefixsum[i-1];
        }
        // return recur(0,n-1,prefixsum);
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return memo(0,n-1,prefixsum,dp);
    }
};