class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        for(int j=i+1;j<n;j++)
        {
            if(nums[j]!=nums[i])
            {
                swap(nums[j],nums[i+1]);
                i++;
            }
        }
        return i+1;
    }
};