class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int ele=0;
        if(n==1)
        {
            return ele;
        }
        int maxi=INT_MAX;
        if(nums[0]>nums[1])
        {
            return ele;
        }
        if(nums[n-1]>nums[n-2])
        {
            return n-1;
        }
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
            {
                maxi=nums[i];
                ele=i;
            }
        }
        return ele;
    }
};