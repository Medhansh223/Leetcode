class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && visited[nrow][ncol]!=1)
            {
                dfs(nrow,ncol,visited,grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(grid[i][j]==1 && visited[i][j]!=1)
                    {
                        dfs(i,j,visited,grid);
                    }
                }
            }
        }
        int enclaves=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && visited[i][j]!=1)
                {
                    enclaves++;
                }
            }
        }
        return enclaves;
    }
};