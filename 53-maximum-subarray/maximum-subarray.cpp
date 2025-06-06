class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0;
        long long maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum = sum + nums[i];
            maxi = max(maxi,sum);
            if(sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};