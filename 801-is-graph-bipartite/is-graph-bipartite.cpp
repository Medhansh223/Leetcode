class Solution {
public:
    bool bfs(int node, int color, vector<int>& colored, vector<vector<int>>& graph)
    {
        queue<int>q;
        q.push(node);
        colored[node]=color;
        while(!q.empty())
        {
            int element=q.front();
            q.pop();
            for(auto adjacentnode: graph[element])
            {
                if(colored[adjacentnode]==-1)
                {
                    if(bfs(adjacentnode,!color,colored,graph)==false)
                    {
                        return false;
                    }
                }
                else if(colored[adjacentnode]==color)
                {
                    return false;
                }
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
                if(bfs(i,0,colored,graph)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};