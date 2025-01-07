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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        vector<int>drow={-1,0,+1,0};
        vector<int>dcol={0,1,0,-1};
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]==0)
                {
                    continue;
                }
                for(int k=0;k<4;k++)
                {
                    int nrow=row+drow[k];
                    int ncol=col+dcol[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
                    {
                        int point=(row*n)+col;
                        int npoint=(nrow*n)+ncol;
                        ds.UnionSize(point,npoint);
                    }
                }
            }
        }
        int maxi=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]==1)
                {
                    continue;
                }
                set<int>components;
                for(int k=0;k<4;k++)
                {
                    int nrow=row+drow[k];
                    int ncol=col+dcol[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
                    {
                        components.insert(ds.find((nrow*n)+ncol));
                    }
                }
                int totalsize=0;
                for(auto it:components)
                {
                    totalsize=totalsize+ds.size[it];
                }
                maxi=max(maxi,totalsize+1);
            }
        }
        for(int cellno=0;cellno<n*n;cellno++)
        {
            maxi=max(maxi,ds.size[ds.find(cellno)]);
        }
        return maxi;
    }
};