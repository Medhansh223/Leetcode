class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        q.push({row,col});
        vector<int>drow = {-1,0,+1,0};
        vector<int>dcol = {0,+1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && visited[nrow][ncol] == 0)
                {
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1' && visited[i][j] == 0)
                {
                    count++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};