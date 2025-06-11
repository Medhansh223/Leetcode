class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int element = -1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                element = i-1;
                break;
            }
        }
        if(element == -1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[element])
            {
                swap(nums[element],nums[i]);
                break;
            }
        }
        sort(nums.begin()+element+1,nums.end());
    }
};