class Solution {
public:
    void bfs(int& time, queue<pair<pair<int,int>,int>>& q, vector<vector<int>>& visited, vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>drow={-1,0,+1,0};
        vector<int>dcol={0,+1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && visited[row][col]!=2)
                {
                    q.push({{row,col},t+1});
                    visited[row][col]=2;
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2 && visited[i][j]!=2)
                {   
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
            }
        }
        int time=0;
        bfs(time,q,visited,grid);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && visited[i][j]!=2)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};