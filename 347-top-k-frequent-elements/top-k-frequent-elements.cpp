class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>freq;
        for(auto it:nums)
        {
            freq[it]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:freq)
        {
            int num = it.first;
            int count = it.second;
            pq.push({count,num});
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<int>result;
        while(!pq.empty())
        {
            int count = pq.top().first;
            int num = pq.top().second;
            pq.pop();
            result.push_back(num);
        }
        return result;
    }
};