class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>row={-1,0,+1,0};
        vector<int>col={0,+1,0,-1};
        vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=r+row[i];
            int ncol=c+col[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(grid[i][j]==1 && !vis[i][j])
                    {
                        dfs(i,j,vis,grid);
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};