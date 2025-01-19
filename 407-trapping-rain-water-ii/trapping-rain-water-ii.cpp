class Solution {
public:
    void bfs(vector<vector<int>>& heightMap, vector<vector<int>>& visited, 
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>& pq, int& water)
    {
        int n=heightMap.size();
        int m=heightMap[0].size();
        vector<int>drow={-1,0,+1,0};
        vector<int>dcol={0,+1,0,-1};
        while(!pq.empty())
        {
            int height=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]!=1)
                {
                    water=water+max(0,height-heightMap[nrow][ncol]);
                    int newheight=max(height,heightMap[nrow][ncol]);
                    pq.push({newheight,{nrow,ncol}});
                    visited[nrow][ncol]=1;
                }
            }
        }
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(visited[i][j]!=1)
                    {
                        visited[i][j]=1;
                        pq.push({heightMap[i][j],{i,j}});
                    }
                }
            }
        }
        int water=0;
        bfs(heightMap,visited,pq,water);
        return water;
    }
};