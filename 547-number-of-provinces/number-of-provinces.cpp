class Solution {
public:
    void dfs(int element, vector<int>& visited, vector<vector<int>>& adj)
    {
        int n=adj.size();
        visited[element]=1;
        for(auto adjacentnode: adj[element])
        {
            if(!visited[adjacentnode])
            {     
                dfs(adjacentnode,visited,adj);        
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
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i,visited,adj);
            }
        }
        return count;
    }
};