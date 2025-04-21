class Solution {
public:
    int memo(int i, vector<vector<int>>& dp, vector<int>& nums, int sum)
    {
        if(i == 0)
        {
            if(sum == 0 && nums[0] == 0)
            {
                return 2;
            }
            if(sum == 0 || nums[0] == sum)
            {
                return 1;
            }
            return 0;
        }
        if(dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        int nonpick = memo(i-1,dp,nums,sum);
        int pick = 0;
        if(nums[i] <= sum)
        {
            pick = memo(i-1,dp,nums,sum - nums[i]);
        }
        dp[i][sum] = nonpick + pick;
        return dp[i][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int i=0;i<n;i++)
        {
            total = total + nums[i];
        }
        int sum = (total - target) / 2;
        if((total - target) < 0 || (total - target) % 2 == 1)
        {
            return 0;
        }
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return memo(n-1,dp,nums,sum);
    }
};