class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);
        int len = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i-1;j++)
            {
                if(nums[j] < nums[i] && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                }
                else if(nums[j] < nums[i] && 1 + dp[j] == dp[i])
                {
                    count[i] = count[i] + count[j];
                }
            }
            len = max(len,dp[i]);
        }
        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(dp[i] == len)
            {
                c = c + count[i];
            }
        }
        return c;
    }
};