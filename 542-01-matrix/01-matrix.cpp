class Solution {
public:
    void bfs(vector<int>&drow, vector<int>&dcol, vector<vector<int>>&visited, vector<vector<int>>&distance, vector<vector<int>>&mat, queue<pair<pair<int,int>,int>>&q)
    {
        int n=mat.size();
        int m=mat[0].size();
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            distance[row][col]=steps;
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0)
                {
                    visited[nrow][ncol]=1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>distance(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        vector<int>drow={-1,0,+1,0};
        vector<int>dcol={0,+1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        bfs(drow,dcol,visited,distance,mat,q);
        return distance;
    }
};