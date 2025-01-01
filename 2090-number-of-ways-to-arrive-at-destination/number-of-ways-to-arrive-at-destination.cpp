class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<long long>distance(n,LLONG_MAX);
        distance[0]=0;
        vector<int>path(n,0);
        path[0]=1;
        int mod=1e9+7;
        while(!pq.empty())
        {
            long long dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int wt=it.second;
                if(dis+wt<distance[adjnode])
                {
                    distance[adjnode]=dis+wt;
                    pq.push({distance[adjnode],adjnode});
                    path[adjnode]=path[node];
                }
                else if(dis+wt==distance[adjnode])
                {
                    path[adjnode]=(path[adjnode]+path[node])%mod;
                }
            }
        }
        return (path[n-1])%mod;
    }
};