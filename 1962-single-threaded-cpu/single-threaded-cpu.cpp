class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<array<long long,3>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(vec.begin(),vec.end());
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        long long time=0;
        long long index=0;
        vector<int>result;
        while(index<n || !pq.empty())
        {
            if(pq.empty() && time<vec[index][0])
            {
                time=vec[index][0];
            }
            while(index<n && vec[index][0]<=time)
            {
                pq.push({vec[index][1],vec[index][2]});
                index++;
            }
            long long pt=pq.top().first;
            long long i=pq.top().second;
            pq.pop();
            time=time+pt;
            result.push_back((int)i);
        }
        return result;
    }
};