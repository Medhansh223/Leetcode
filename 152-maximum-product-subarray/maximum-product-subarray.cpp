class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1;
        int suff = 1;
        int maxi = 0;
        if(n==1)
        {
            return nums[0];
        }
        for(int i=0;i<n;i++)
        {
            if(pre == 0)
            {
                pre = 1;
            }
            if(suff == 0)
            {
                suff = 1;
            }
            pre = pre * nums[i];
            suff = suff * nums[n-i-1];
            maxi = max({maxi,pre,suff});
        }
        return maxi;
    }
};