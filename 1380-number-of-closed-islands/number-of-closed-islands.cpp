class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int r, int c)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(r < 0 || r >= n || c < 0 || c >= m)
        {
            return false;
        }
        if(grid[r][c] == 1)
        {
            return true;
        }
        grid[r][c] = 1;
        bool up = dfs(grid,r-1,c);
        bool left = dfs(grid,r,c-1);
        bool down = dfs(grid,r+1,c);
        bool right = dfs(grid,r,c+1);
        return up && left && down && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0)
                {
                    if(dfs(grid,i,j) == true)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};