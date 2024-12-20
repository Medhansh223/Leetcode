class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        visited[row][col]=1;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && visited[nrow][ncol]!=1)
                {
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m));
        int islands=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]!=1)
                {
                    islands++;
                    bfs(i,j,visited,grid);   
                }
            }
        }
        return islands;
    }
};