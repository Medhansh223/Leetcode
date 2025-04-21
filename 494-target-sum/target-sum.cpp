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
    int tabu(int n, vector<vector<int>>& dp, vector<int>& nums, int sum)
    {
        if(nums[0] == 0)
        {
            dp[0][0] = 2;
        }
        else
        {
            dp[0][0] = 1;
        }
        if(nums[0] != 0 && nums[0] <= sum)
        {
            dp[0][nums[0]] = 1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                int nonpick = dp[i-1][j];
                int pick = 0;
                if(nums[i] <= j)
                {
                    pick = dp[i-1][j - nums[i]];
                }
                dp[i][j] = nonpick + pick;
            }
        }
        return dp[n-1][sum];
    }
    int space(int n, vector<int>& prev, vector<int>& nums, int sum)
    {
        if(nums[0] == 0)
        {
            prev[0] = 2;
        }
        else
        {
            prev[0] = 1;
        }
        if(nums[0] != 0 && nums[0] <= sum)
        {
            prev[nums[0]] = 1;
        }
        for(int i=1;i<n;i++)
        {
            vector<int>temp(sum+1,0);
            for(int j=0;j<=sum;j++)
            {
                int nonpick = prev[j];
                int pick = 0;
                if(nums[i] <= j)
                {
                    pick = prev[j - nums[i]];
                }
                temp[j] = nonpick + pick;
            }
            prev = temp;
        }
        return prev[sum];
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
        // vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        // return memo(n-1,dp,nums,sum);

        // vector<vector<int>>dp(n,vector<int>(sum+1,0));
        // return tabu(n,dp,nums,sum);

        vector<int>dp(sum+1,0);
        return space(n,dp,nums,sum);
    }
};