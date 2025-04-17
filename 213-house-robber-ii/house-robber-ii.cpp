class Solution {
public:
    int memo(vector<int>&dp,int n,vector<int>&nums)
    {
        if(n==0)
        {
            return nums[n];
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int pick=nums[n];
        if(n-2>=0)
        {
            pick=pick+memo(dp,n-2,nums);
        }
        int nonpick=memo(dp,n-1,nums);
        dp[n]=max(pick,nonpick);
        return dp[n];
    }
    int tabu(vector<int>&dp,int n,vector<int>&nums)
    {
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i-2>=0)
            {
                pick=pick+dp[i-2];
            }
            int nonpick=dp[i-1];
            dp[i]=max(pick,nonpick);
        }
        return dp[n-1];
    }
    int space(int n,vector<int>&nums)
    {
        int prev1=nums[0];
        int prev2=0;
        int curr;
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i-2>=0)
            {
                pick=pick+prev2;
            }
            int nonpick=prev1;
            curr=max(pick,nonpick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int robo(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        // return memo(dp,n-1,nums);
        // return tabu(dp,n,nums);
        return space(n,nums);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        vector<int>left;
        vector<int>right;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                left.push_back(nums[i]);
            }
            if(i!=n-1)
            {
                right.push_back(nums[i]);
            }
        }
        return max(robo(left),robo(right));
    }
};