class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int maxi = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                sum = sum + nums[i];
            }
            else
            {
                sum = nums[i];
            }
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};