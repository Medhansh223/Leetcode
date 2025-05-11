class Solution {
public:
    int memo(int i, int target, vector<vector<int>>& dp, vector<int>& nums)
    {
        if(i == 0)
        {
            if(nums[0] == 0 && target == 0)
            {
                return true;
            }
            if(target == 0 || nums[0] == target)
            {
                return true;
            }
            return false;
        }
        if(dp[i][target] != -1)
        {
            return dp[i][target];
        }
        bool not_pick = memo(i-1,target,dp,nums);
        bool pick = false;
        if(nums[i] <= target)
        {
            pick = memo(i-1,target - nums[i],dp,nums);
        }
        dp[i][target] = pick || not_pick;
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
        int target = sum / 2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return memo(n-1,target,dp,nums);

        // vector<vector<int>>dp(n,vector<int>(target+1,false));
        // return memo(n,target,dp,nums);

        // vector<int>dp(target+1,false);
        // return memo(n,target,dp,nums);
    }
};