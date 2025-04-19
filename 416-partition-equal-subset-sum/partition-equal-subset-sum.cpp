class Solution {
public:
    int memo(int n, vector<vector<int>>& dp, vector<int>& nums, int target)
    {
        if(target == 0)
        {
            return true;
        }
        if(n == 0)
        {
            return nums[0] == target;
        }
        if(dp[n][target] != -1)
        {
            return dp[n][target];
        }
        bool non_pick = memo(n-1,dp,nums,target);
        bool pick = false;
        if(nums[n] <= target)
        {
            pick = memo(n-1,dp,nums,target - nums[n]);
        }
        dp[n][target] = pick || non_pick;
        return dp[n][target];
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
        int target = (sum/2);
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return memo(n-1,dp,nums,target);
    }
};