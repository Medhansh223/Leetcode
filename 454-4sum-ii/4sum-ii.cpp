class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int>mpp;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                mpp[nums1[i]+nums2[j]]++;
            }
        }
        int count = 0;
        for(int i=0;i<nums3.size();i++)
        {
            for(int j=0;j<nums4.size();j++)
            {
                int target = -(nums3[i]+nums4[j]);
                if(mpp.find(target) != mpp.end())
                {
                    count = count + mpp[target];
                }
            }
        }
        return count;
    }
};