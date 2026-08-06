class Solution {
public:
    int memo(int i, vector<int>& nums, vector<vector<int>>& dp, int target)
    {
        if(i == 0)
        {
            if(target == 0 || nums[i] == target)
            {
                return true;
            }
            return false;
        }
        if(dp[i][target] != -1)
        {
            return dp[i][target];
        }
        bool notpick = memo(i-1,nums,dp,target);
        bool pick = 0;
        if(nums[i] <= target)
        {
            pick = memo(i-1,nums,dp,target - nums[i]);
        }
        dp[i][target] = pick || notpick;
        return dp[i][target];
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
        return memo(n-1,nums,dp,target);
    }
};