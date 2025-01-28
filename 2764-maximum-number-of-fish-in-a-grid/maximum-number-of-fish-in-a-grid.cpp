class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        vector<int>drow={-1,0,+1,0};
        vector<int>dcol={0,+1,0,-1};
        int sum=grid[row][col];
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]>0 && visited[nrow][ncol]!=1)
                {
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                    sum+=grid[nrow][ncol];
                } 
            }
        }
        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int maxsum = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]>0 && visited[i][j]!=1)
                {
                    maxsum=max(maxsum,bfs(i,j,visited,grid));
                }
            }
        }
        return maxsum;
    }
};