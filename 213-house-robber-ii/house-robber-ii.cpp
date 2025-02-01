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
    int optimization(vector<int>& nums)
    {
        int n=nums.size();
        int curr;
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>=2)
            {
                pick=pick+prev2;
            }
            int non_pick=prev1;
            curr=max(pick,non_pick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }

    int robo(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans1 = memoization(nums,dp,n-1);
        int ans2 = tabulation(nums,dp,n);
        int ans3 = optimization(nums);
        return ans3;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        vector<int>dp(n,-1);
        vector<int>firstnumber;
        vector<int>lastnumber;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                firstnumber.push_back(nums[i]);
            }
            if(i!=(n-1))
            {
                lastnumber.push_back(nums[i]);
            }
        }
        // int ans1 = memoization(nums,dp,n-1);
        // int ans2 = tabulation(nums,dp,n);
        int ans3 = max(robo(firstnumber), robo(lastnumber));
        return ans3;
    }
};