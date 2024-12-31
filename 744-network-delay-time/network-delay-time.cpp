class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        vector<int>distance(n+1,INT_MAX);
        distance[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int wt=it.second;
                if(dist+wt<distance[adjnode])
                {
                    distance[adjnode]=dist+wt;
                    pq.push({distance[adjnode],adjnode});
                }
            }
        }
        int result=0;
        for(int i=1;i<=n;i++)
        {
            if(distance[i]==INT_MAX)
            {
                return -1;
            }
            result=max(result,distance[i]);
        }
        return result;
    }
};