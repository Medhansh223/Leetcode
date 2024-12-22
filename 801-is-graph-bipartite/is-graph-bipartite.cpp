class Solution {
public:
    bool dfs(int node, int color, vector<int>& colored, vector<vector<int>>& graph)
    {
        int n=graph.size();
        colored[node]=color;
        for(auto adjacentnode: graph[node])
        {
            if(colored[adjacentnode]==-1)
            {
                if(dfs(adjacentnode, !color, colored, graph)==false)
                {
                    return false;
                }
            }
            else if(colored[adjacentnode]==color)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colored(n,-1);
        for(int i=0;i<n;i++)
        {
            if(colored[i]==-1)
            {
                if(dfs(i,0,colored,graph)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};