class DisjointSet{
public:
    vector<int>parent,rank,size;
    DisjointSet(int n)
    {
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int find(int n)
    {
        if(n==parent[n])
        {
            return n;
        }
        return parent[n]=find(parent[n]);
    }
    void UnionRank(int u, int v)
    {
        int ulp_u=parent[u];
        int ulp_v=parent[v];
        if(ulp_u == ulp_v)
        {
            return;
        }
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u])
        {
            parent[ulp_v]=ulp_u;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionSize(int u, int v)
    {
        int ulp_u=parent[u];
        int ulp_v=parent[v];
        if(ulp_u == ulp_v)
        {
            return;
        }
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]=size[ulp_v]+size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]=size[ulp_u]+size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=0;
        DisjointSet ds(n);
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.find(u) == ds.find(v))
            {
                edges++;
            }
            else
            {
                ds.UnionSize(u,v);
            }
        }
        int components=0;
        for(int i=0;i<n;i++)
        {
            if(ds.find(i)==i)
            {
                components++;
            }
        }
        int ans=components-1;
        if(edges>=ans)
        {
            return ans;
        }
        return -1;
    }
};