class Solution {
public:
    bool memoization(int n, int target, vector<vector<int>>& dp, vector<int>& nums)
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
        bool not_pick = memoization(n-1,target,dp,nums);
        bool pick = false;
        if(nums[n]<=target)
        {
            pick = memoization(n-1,target-nums[n],dp,nums);
        }
        dp[n][target] = pick || not_pick;
        return dp[n][target];
    }

    bool tabulation(int n, int k, vector<vector<int>>& dp, vector<int>& nums)
    {
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if(nums[0]<=k)
        {
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int target=1;target<=k;target++)
            {
                bool not_pick = dp[i-1][target];
                bool pick = false;
                if(nums[i]<=target)
                {
                    pick = dp[i-1][target-nums[i]];
                }
                dp[i][target] = pick || not_pick;
            }
        }
        return dp[n-1][k];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum + nums[i];
        }
        if(sum % 2 == 1)
        {
            return false;
        }
        int target = sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return memoization(n-1,target,dp,nums);

        // vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        // return tabulation(n,target,dp,nums);

        // vector<bool>dp(sum+1,-1));
        // return optimisation(n,target,dp,nums);
    }
};