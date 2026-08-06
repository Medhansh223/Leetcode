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
    bool tabu(int n, vector<int>& nums, vector<vector<int>>& dp, int target)
    {
        dp[0][0] = true;
        if(nums[0] <= target)
        {
           dp[0][nums[0]] = true; 
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                bool notpick = dp[i-1][j];
                bool pick = false;
                if(nums[i] <= j)
                {
                    pick = dp[i-1][j - nums[i]];
                }
                dp[i][j] = pick || notpick;
            }
        }
        return dp[n-1][target];
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
        // vector<vector<int>>dp(n,vector<int>(target+1,-1));
        // return memo(n-1,nums,dp,target);
        vector<vector<int>>dp(n,vector<int>(target+1,false));
        return tabu(n,nums,dp,target);
    }
};