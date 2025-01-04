class DisjointSet{
    vector<int> parent,rank,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int find(int X){
        if(X==parent[X])
        {
            return X;
        }
        return parent[X]=find(parent[X]);
    }
    void unionRank(int X,int Z) // union by rank
    {
    	int ulp_u=parent[X];
    	int ulp_v=parent[Z];
    	if(ulp_u==ulp_v)
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
    void unionSize(int X,int Z) // union by size
    {
        int ulp_u=parent[X];
        int ulp_v=parent[Z];
        if(ulp_u==ulp_v)
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
        DisjointSet ds(n);
        int extraedges=0;
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.find(u)==ds.find(v))
            {
                extraedges++;
            }
            else
            {
                ds.unionSize(u,v);
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
        if(extraedges>=ans)
        {
            return ans;
        }
        return -1;
    }
};