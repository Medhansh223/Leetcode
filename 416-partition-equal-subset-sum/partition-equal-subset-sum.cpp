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
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return memo(n-1,s,dp,nums);
    }
};