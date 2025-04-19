class Solution {
public:
    bool memo(int n,int target, vector<vector<int>>&dp, vector<int>&nums)
    {
        if(target==0)
        {
            return true;
        }
        if(n==0)
        {
            return nums[0]==target;
        }
        if(dp[n][target]!=-1)
        {
            return dp[n][target];
        }
        bool nonpick=memo(n-1,target,dp,nums);
        bool pick=false;
        if(nums[n]<=target)
        {
            pick=memo(n-1,target-nums[n],dp,nums);
        }
        dp[n][target]=pick||nonpick;
        return dp[n][target];
    }
    bool tabu(int n, int target, vector<vector<bool>>&dp, vector<int>&nums)
    {
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if(nums[0]<=target)
        {
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                bool nonpick=dp[i-1][j];
                bool pick=false;
                if(nums[i]<=j)
                {
                    pick=dp[i-1][j-nums[i]];
                }
                dp[i][j]=pick||nonpick;
            }
        }
        return dp[n-1][target];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }
        if(sum%2==1)
        {
            return false;
        }
        int s=sum/2;
        // vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        // return memo(n-1,s,dp,nums);
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        return tabu(n,s,dp,nums);
    }
};