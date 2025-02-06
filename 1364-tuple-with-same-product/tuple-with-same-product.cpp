class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int product = nums[i]*nums[j];
                count = count + (8*mpp[product]);
                mpp[product]++;
            }
        }
        return count;
    }
};