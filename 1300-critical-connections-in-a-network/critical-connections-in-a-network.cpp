class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis, vector<int>& time, vector<int>& low_time, vector<vector<int>>& bridges, int &timer)
    {
        vis[node]=1;
        time[node]=low_time[node]=timer;
        timer++;
        for(auto it: adj[node])
        {
            if(it==parent)
            {
                continue;
            }
            if(!vis[it])
            {
                dfs(it,node,adj,vis,time,low_time,bridges,timer);
                low_time[node]=min(low_time[node], low_time[it]);
                if(time[node]<low_time[it])
                {
                    bridges.push_back({node,it});
                }
            }
            else
            {
                low_time[node]=min(low_time[node], low_time[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto it: connections)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        vector<int>time(n,0);
        vector<int>low_time(n,0);
        int timer=1;
        vector<vector<int>>bridges;
        dfs(0,-1,adj,vis,time,low_time,bridges,timer);
        return bridges;
    }
};