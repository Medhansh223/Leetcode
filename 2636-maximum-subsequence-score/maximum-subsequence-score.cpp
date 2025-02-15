class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++)
        {
            vec[i]={nums2[i],nums1[i]};//nums2,nums1
        }
        sort(vec.rbegin(),vec.rend());
        priority_queue<int,vector<int>,greater<int>>pq;//nums1
        long long ksum=0;
        for(int i=0;i<k;i++)
        {
            ksum=ksum+vec[i].second;
            pq.push(vec[i].second);
        }
        long long result=ksum*vec[k-1].first;
        for(int i=k;i<n;i++)
        {
            ksum=ksum+vec[i].second-pq.top();
            pq.pop();
            pq.push(vec[i].second);
            result=max(result,ksum*vec[i].first);
        }
        return result;
    }
};