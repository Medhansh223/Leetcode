class Solution {
public:
    int memoization(vector<int>& nums, vector<int>& dp, int n)
    {
        if(n==0)
        {
            return nums[n];
        }
        if(n<0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int pick = nums[n] + memoization(nums,dp,n-2);
        int not_pick = 0 + memoization(nums,dp,n-1);
        dp[n] = max(pick, not_pick);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans1 = memoization(nums,dp,n-1);
        return ans1;
    }
};