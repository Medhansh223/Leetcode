class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int result=0;
        if(n%2==1)
        {
            for(int i=0;i<m;i++)
            {
                result=result^nums2[i];
            }
        }
        if(m%2==1)
        {
            for(int i=0;i<n;i++)
            {
                result=result^nums1[i];
            }
        }
        return result;
    }
};