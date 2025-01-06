class DisjointSet{
    vector<int>parent,rank,size;
public:
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
    void UnionSize(int u, int v)
    {
        int ulp_u=find(u);
        int ulp_v=find(v);
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones)
        {
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        DisjointSet ds(maxrow+maxcol+1);
        map<int,bool>mpp;
        for(auto it:stones)
        {
            int row=it[0];
            int col=it[1]+maxrow+1;
            ds.UnionSize(row,col);
            mpp[row]=true;
            mpp[col]=true;
        }

        int count=0;
        for(auto it:mpp)
        {
            if(ds.find(it.first)==it.first)
            {
                count++;
            }
        }
        return n-count;
    }
};