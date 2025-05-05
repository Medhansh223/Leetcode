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
    int tabu(int n,vector<int>&dp,vector<int>&arr,int k)
    {
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            int maxi=INT_MIN;
            int maxsum=INT_MIN;
            int len=0;
            for(int j=i;j<min(n,i+k);j++)
            {
                len++;
                maxi=max(maxi,arr[j]);
                int sum=len*maxi+dp[j+1];
                maxsum=max(maxsum,sum);
            }
            dp[i]=maxsum;
        }
        return dp[0];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        // vector<int>dp(n,-1);
        // return memo(0,n,dp,arr,k);
        vector<int>dp(n+1,-1);
        return tabu(n,dp,arr,k);
    }
};