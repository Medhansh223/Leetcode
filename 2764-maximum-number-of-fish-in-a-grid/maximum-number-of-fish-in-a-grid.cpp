class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&visited,vector<vector<int>>&grid,int &sum)
    {
        int n=grid.size();
        int m=grid[0].size();
        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,+1,0,-1};
        visited[r][c]=1;
        
           
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]>0)
                {
                    sum=sum+grid[nrow][ncol];
                    dfs(nrow,ncol,visited,grid,sum);
                }
            }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int maxsum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]>0)
                {
                    int sum=grid[i][j];
                    dfs(i,j,visited,grid,sum);
                    maxsum=max(maxsum,sum);
                }
            }
        }
        return maxsum;
    }
};