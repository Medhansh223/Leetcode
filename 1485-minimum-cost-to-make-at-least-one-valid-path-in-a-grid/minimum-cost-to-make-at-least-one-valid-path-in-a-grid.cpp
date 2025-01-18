class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<int>drow={0,0,1,-1};
        vector<int>dcol={1,-1,0,0};
        while(!pq.empty())
        {
            int cost=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1)
            {
                return cost;
            }
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int newcost;
                    if(grid[row][col]==i+1)
                    {
                        newcost=cost;
                    }
                    else
                    {
                        newcost=cost+1;
                    }
                    if(newcost<dis[nrow][ncol])
                    {
                        pq.push({newcost,{nrow,ncol}});
                        dis[nrow][ncol]=newcost;
                    }
                }
            }
        }
        return -1;
    }
};