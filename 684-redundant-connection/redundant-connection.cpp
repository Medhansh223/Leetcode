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
        int ulp_u=find(u);
        int ulp_v=find(v);
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
    bool UnionSize(int u, int v)
    {
        int ulp_u=find(u);
        int ulp_v=find(v);
        if(ulp_u == ulp_v)
        {
            return false;
        }
        else
        {
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
            return true;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            if(!ds.UnionSize(u,v))
            {
                return it;
            }
        }
        return {};
    }
};