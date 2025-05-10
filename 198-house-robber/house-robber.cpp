class Solution {
public:
    int memo(int i, vector<int>& dp, vector<int>& nums)
    {
        if(i == 0)
        {
            return nums[0];
        }
        if(dp[i] != - 1)
        {
            return dp[i];
        }
        int not_pick = memo(i-1,dp,nums);
        int pick = nums[i];
        if(i >= 2)
        {
            pick = pick + memo(i-2,dp,nums);
        }
        dp[i] = max(pick,not_pick);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return memo(n-1,dp,nums);
    }
};