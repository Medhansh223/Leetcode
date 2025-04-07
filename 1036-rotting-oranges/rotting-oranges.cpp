class Solution {
public:
    void bfs(queue<pair<pair<int,int>,int>>&q,vector<vector<int>>&vis,vector<vector<int>>&grid,int &time)
    {
        int row[4]={+1,0,-1,0};
        int col[4]={0,+1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+row[i];
                int ncol=c+col[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        int time=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        bfs(q,vis,grid,time);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]!=2)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};