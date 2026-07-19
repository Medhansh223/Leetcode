class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u][v]=wt;
            adj[v][u]=wt;
        }
        for(int i=0;i<n;i++)
        {
            adj[i][i]=0;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(adj[i][k]!=INT_MAX && adj[k][j]!=INT_MAX)
                    {
                        adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
                    }
                }
            }
        }
        int citycount=n;
        int cityno=-1;
        for(int city=0;city<n;city++)
        {
            int count=0;
            for(int adjcity=0;adjcity<n;adjcity++)
            {
                if(adj[city][adjcity]<=distanceThreshold)
                {
                    count++;
                }
            }
            if(count<=citycount)
            {
                citycount=count;
                cityno=city;
            }
        }
        return cityno;
    }
};