class Solution {
public:
    void bfs(vector<vector<int>>& isWater, vector<vector<int>>& visited, vector<vector<int>>& distance, queue<pair<int,pair<int,int>>>& q)
    {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<int>drow={-1,0,+1,0};
        vector<int>dcol={0,+1,0,-1};
        while(!q.empty())
        {
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            distance[row][col]=dis;
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0)
                {
                    q.push({dis+1,{nrow,ncol}});
                    visited[nrow][ncol]=1;
                }
            }
        }
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>distance(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j]==1 && visited[i][j]!=1)
                {
                    visited[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }
        bfs(isWater,visited,distance,q);
        return distance;
    }
};