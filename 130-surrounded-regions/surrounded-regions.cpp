class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& board)
    {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        visited[row][col]=1;
        q.push({row,col});
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && visited[nrow][ncol]!=1)
                {
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O' && visited[0][j]!=1)
            {
                bfs(0,j,visited,board);
            }
            if(board[n-1][j]=='O' && visited[n-1][j]!=1)
            {
                bfs(n-1,j,visited,board);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && visited[i][0]!=1)
            {
                bfs(i,0,visited,board);
            }
            if(board[i][m-1]=='O' && visited[i][m-1]!=1)
            {
                bfs(i,m-1,visited,board);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && visited[i][j]!=1)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};