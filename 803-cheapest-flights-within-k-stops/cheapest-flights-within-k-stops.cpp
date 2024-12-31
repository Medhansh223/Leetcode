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
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>distance(n,INT_MAX);
        distance[src]=0;
        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int dist=q.front().second.second;
            q.pop();
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int wt=it.second;
                if(dist+wt<distance[adjnode] && stops<=k)
                {
                    distance[adjnode]=dist+wt;
                    q.push({stops+1,{adjnode,distance[adjnode]}});
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