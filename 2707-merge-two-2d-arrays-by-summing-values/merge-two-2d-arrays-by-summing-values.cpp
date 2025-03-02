class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>result;
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        while(i<n && j<m)
        {
            int id1=nums1[i][0];
            int id2=nums2[j][0];
            if(id1==id2)
            {
                int sum=nums1[i][1]+nums2[j][1];
                result.push_back({id1,sum});
                i++;
                j++;
            }
            else if(id1<id2)
            {
                result.push_back({id1,nums1[i][1]});
                i++;
            }
            else
            {
                result.push_back({id2,nums2[j][1]});
                j++;
            }
        }
        while(i<n)
        {
            result.push_back({nums1[i][0],nums1[i][1]});
            i++;
        }
        while(j<m)
        {
            result.push_back({nums2[j][0],nums2[j][1]});
            j++;
        }
        return result;
    }
};