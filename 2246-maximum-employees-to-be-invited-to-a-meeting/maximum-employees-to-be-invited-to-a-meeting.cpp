class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
            indegree[favorite[i]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>depth(n,1);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            int neigh=favorite[node];
            depth[neigh]=max(depth[neigh],depth[node]+1);
            indegree[neigh]--;
            if(indegree[neigh]==0)
            {
                q.push(neigh);
            }
        }
        int cycle=0;
        int longestcycle=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++)
        {
            // if(indegree[i]==0)
            // {
            //     continue;
            // }
            if(indegree[i]>0)
            {
                int cyclelength=0;
                int current=i;
                while (!visited[current]) 
                {
                    visited[current] = 1;
                    cyclelength++;
                    current = favorite[current];
                }
                if(cyclelength==2)
                {
                    cycle=cycle+depth[i]+depth[favorite[i]];
                }
                else
                {
                    longestcycle=max(longestcycle,cyclelength);
                }
            }
        }
        return max(longestcycle,cycle);
    }
};
// 0->2