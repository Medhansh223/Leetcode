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
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({1,{0,0}});
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        distance[0][0]=1;
        vector<int>drow={-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int>dcol={-1, 0, 1, 1, 1, 0, -1, -1};
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
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
                    pq.push({distance[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};