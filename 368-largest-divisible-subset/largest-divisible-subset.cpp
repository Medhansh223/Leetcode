class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        sort(nums.begin(),nums.end());
        int maxi=1;
        vector<int>parent(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i])
                {
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
        }
        vector<int>temp;
        int ans=-1;
        int last=-1;
        for(int i=0;i<n;i++)
        {
            if(dp[i]>ans)
            {
                ans=dp[i];
                last=i;
            }
        }
        temp.push_back(nums[last]);
        while(parent[last]!=last)
        {
            last=parent[last];
            temp.push_back(nums[last]);
        }
        return temp;
    }
};