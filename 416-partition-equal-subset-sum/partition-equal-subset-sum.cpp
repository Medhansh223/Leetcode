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
    bool tabu(int n, int target, vector<vector<int>>& dp, vector<int>& nums)
    {
        if(nums[0] == 0)
        {
            dp[0][0] = true;
        }
        else
        {
            dp[0][0] = true;
        }
        if(nums[0] != 0 && nums[0] <= target)
        {
            dp[0][nums[0]] = true;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                bool not_pick = dp[i-1][j];
                bool pick = false;
                if(nums[i] <= j)
                {
                    pick = dp[i-1][j - nums[i]];
                }
                dp[i][j] = pick || not_pick;
            }
        }
        return dp[n-1][target];
    }
    bool space(int n, int target, vector<int>& dp, vector<int>& nums)
    {
        if(nums[0] == 0)
        {
            dp[0] = true;
        }
        else
        {
            dp[0] = true;
        }
        if(nums[0] != 0 && nums[0] <= target)
        {
            dp[nums[0]] = true;
        }
        for(int i=1;i<n;i++)
        {
            vector<int>temp(target+1,false);
            for(int j=0;j<=target;j++)
            {
                bool not_pick = dp[j];
                bool pick = false;
                if(nums[i] <= j)
                {
                    pick = dp[j - nums[i]];
                }
                temp[j] = pick || not_pick;
            }
            dp = temp;
        }
        return dp[target];
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
        // vector<vector<int>>dp(n,vector<int>(target+1,-1));
        // return memo(n-1,target,dp,nums);

        // vector<vector<int>>dp(n,vector<int>(target+1,false));
        // return tabu(n,target,dp,nums);

        vector<int>dp(target+1,false);
        return space(n,target,dp,nums);
    }
};