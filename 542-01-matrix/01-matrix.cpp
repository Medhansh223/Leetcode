class Solution {
public:
    void bfs(vector<vector<int>>& mat, vector<vector<int>>& visited, vector<vector<int>>& distance, queue<pair<pair<int,int>,int>>& q)
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>drow={-1,0,+1,0};
        vector<int>dcol={0,+1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int s=q.front().second;
            q.pop();
            distance[r][c]=s;
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0)
                {
                    q.push({{nrow,ncol},s+1});
                    visited[nrow][ncol]=1;
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m));
        vector<vector<int>>distance(n,vector<int>(m));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0 && visited[i][j]!=1)
                {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        bfs(mat,visited,distance,q);
        return distance;
    }
};