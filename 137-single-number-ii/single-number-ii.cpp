class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0;
        int n=nums.size();
        int twos=0;
        for(int i=0;i<n;i++)
        {
            ones=(ones^nums[i])&(~twos);
            twos=(twos^nums[i])&(~ones);
        }
        return ones;
    }
};