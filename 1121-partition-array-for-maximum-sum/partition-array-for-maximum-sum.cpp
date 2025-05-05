class Solution {
public:
    int memo(int ind,int n,vector<int>&dp,vector<int>&arr,int k)
    {
        if(ind==n)
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int maxi=INT_MIN;
        int maxsum=INT_MIN;
        int len=0;
        for(int j=ind;j<min(n,ind+k);j++)
        {
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+memo(j+1,n,dp,arr,k);
            maxsum=max(maxsum,sum);
        }
        dp[ind]=maxsum;
        return dp[ind];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return memo(0,n,dp,arr,k);
    }
};