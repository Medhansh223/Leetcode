class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            distance[u][v]=wt;
            distance[v][u]=wt;
        }
        for(int i=0;i<n;i++)
        {
            distance[i][i]=0;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(distance[i][k]!=INT_MAX && distance[k][j]!=INT_MAX)
                    {
                        distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
                    }
                }
            }
        }
        int countcity=n;
        int cityno=-1;
        for(int city=0;city<n;city++)
        {
            int count=0;
            for(int adjcity=0;adjcity<n;adjcity++)
            {
                if(distance[city][adjcity]<=distanceThreshold)
                {
                    count++;
                }
            }
            if(count<=countcity)
            {
                countcity=count;
                cityno=city;
            }
        }
        return cityno;
    }
};