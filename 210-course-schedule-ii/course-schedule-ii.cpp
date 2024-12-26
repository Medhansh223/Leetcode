class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(auto adjacentnode:prerequisites)
        {
            adj[adjacentnode[1]].push_back(adjacentnode[0]);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto adjacentnode:adj[i])
            {
                indegree[adjacentnode]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto adjacentnode:adj[node])
            {
                indegree[adjacentnode]--;
                if(indegree[adjacentnode]==0)
                {
                    q.push(adjacentnode);
                }
            }
        }
        if(topo.size()==n)
        {
            return topo;
        }
        return {};
    }
};