class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1)
        {
            if(grid[0][0]==0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        if(grid[0][0]==1 || grid[n-1][n-1]==1) 
        {
            return -1;
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        distance[0][0]=1;
        vector<int>drow={-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int>dcol={-1, 0, 1, 1, 1, 0, -1, -1};
        while(!q.empty())
        {
            int dist=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dist+1<distance[nrow][ncol])
                {
                    distance[nrow][ncol]=dist+1;
                    if(nrow==n-1 && ncol==n-1)
                    {
                        return dist+1;
                    }
                    q.push({distance[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};