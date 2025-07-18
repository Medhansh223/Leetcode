class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{src,0}});
        vector<int>distance(n,INT_MAX);
        distance[src]=0;
        while(!pq.empty())
        {
            int stops=pq.top().first;
            int node=pq.top().second.first;
            int dist=pq.top().second.second;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int wt=it.second;
                if(dist+wt<distance[adjnode] && stops<=k)
                {
                    distance[adjnode]=dist+wt;
                    pq.push({stops+1,{adjnode,distance[adjnode]}});
                }
            }
        }
        if(distance[dst]==INT_MAX)
        {
            return -1;
        }
        return distance[dst];
    }
};