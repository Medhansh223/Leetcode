class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
        {
            return -1;
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        distance[0][0] = 1;
        vector<int>row = {-1,-1,0,+1,+1,+1,0,-1};
        vector<int>col = {0,+1,+1,+1,0,-1,-1,-1};
        while(!q.empty())
        {
            int dis = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            if(r == n-1 && c == m-1)
            {
                return dis;
            }
            for(int i=0;i<8;i++)
            {
                int nrow = r + row[i];
                int ncol = c + col[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 0 && dis + 1 < distance[nrow][ncol])
                {
                    q.push({dis+1,{nrow,ncol}});
                    distance[nrow][ncol] = dis + 1;
                }
            }
        }
        return -1;
    }
};