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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        map<string,int>mpp;
        for(int i=0;i<n;i++)
        {
            int m=accounts[i].size();
            for(int j=1;j<m;j++)
            {
                string mail=accounts[i][j];
                if(mpp.find(mail)==mpp.end())
                {
                    mpp[mail]=i;
                }
                else
                {
                    ds.UnionSize(i,mpp[mail]);
                }
            }
        }
        vector<vector<string>>merge(n);
        for(auto it:mpp)
        {
            string mail=it.first;
            int node=ds.find(it.second);
            merge[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            vector<string>result;
            if(merge[i].size()==0)
            {
                continue;
            }
            result.push_back(accounts[i][0]);
            for(auto it:merge[i])
            {
                result.push_back(it);
            }
            ans.push_back(result);
        }
        return ans;

    }
};