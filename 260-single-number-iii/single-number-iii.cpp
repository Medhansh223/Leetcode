class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long xor1=0;
        for(int i=0;i<n;i++)
        {
            xor1=xor1^nums[i];
        }
        int right_bit = int(xor1 ^ (xor1 & (xor1-1)));
        int b1=0;
        int b2=0;
        for(int i=0;i<n;i++)
        {
            if((nums[i] & right_bit)==0)
            {
                b1=b1^nums[i];
            }
            else
            {
                b2=b2^nums[i];
            }
        }
        return {b1,b2};
    }
};