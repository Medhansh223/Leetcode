class Solution {
public:
    int recur(vector<int>& nums, int i)
    {
        if(i == 0)
        {
            return nums[i];
        }
        int not_pick = recur(nums,i-1);
        int pick = nums[i];
        if(i >= 2)
        {
            pick = pick + recur(nums,i-2);
        }
        return max(pick, not_pick);
    }
    int memo(vector<int>& dp, vector<int>& nums, int i)
    {
        if(i == 0)
        {
            return nums[i];
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        int not_pick = memo(dp,nums,i-1);
        int pick = nums[i];
        if(i >= 2)
        {
            pick = pick + memo(dp,nums,i-2);
        }
        dp[i] = max(pick, not_pick);
        return dp[i];
    }
    int tabu(vector<int>& dp, vector<int>& nums, int n)
    {
        dp[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            int not_pick = dp[i-1];
            int pick = nums[i];
            if(i >= 2)
            {
                pick = pick + dp[i-2];
            }
            dp[i] = max(pick, not_pick);
        }
        return dp[n-1];
    }
    int space(vector<int>& nums, int n)
    {
        int prev1 = nums[0];
        int prev2 = 0;
        int curr;
        for(int i=1;i<n;i++)
        {
            int not_pick = prev1;
            int pick = nums[i];
            if(i >= 2)
            {
                pick = pick + prev2;
            }
            curr = max(pick, not_pick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // return recur(nums, n-1);
        vector<int>dp(n,-1);
        // return memo(dp, nums, n-1);
        // return tabu(dp, nums, n);
        return space(nums, n);
    }
};