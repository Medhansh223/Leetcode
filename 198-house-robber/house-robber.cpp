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
    int tabulation(vector<int>& nums, vector<int>& dp, int n)
    {
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>=2)
            {
                pick=pick+dp[i-2];
            }
            int non_pick=dp[i-1];
            dp[i]=max(pick,non_pick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        // int ans1 = memoization(nums,dp,n-1);
        int ans2 = tabulation(nums,dp,n);
        return ans2;
    }
};