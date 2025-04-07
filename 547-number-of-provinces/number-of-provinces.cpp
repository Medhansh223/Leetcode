class Solution {
public:
    void bfs(int node,vector<int>&vis,vector<vector<int>>&adj)
    {
        vis[node]=1;
        queue<int>q;
        q.push(node);
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();
            for(auto it:adj[ele])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                // bfs(i,vis,adj);
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};

// 1 2 3
// [1 1 0] 1
// [1 1 0] 2
// [0 0 1] 3