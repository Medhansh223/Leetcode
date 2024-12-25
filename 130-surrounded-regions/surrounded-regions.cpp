class Solution {
public:
    void dfs(int row, int col, queue<pair<int,int>>& q, vector<vector<int>>& visited, vector<vector<char>>& board)
    {
        int n=board.size();
        int m=board[0].size();
        vector<int>drow={-1,0,+1,0};
        vector<int>dcol={0,+1,0,-1};
        visited[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && visited[nrow][ncol]!=1)
            {
                dfs(nrow,ncol,q,visited,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(board[i][j]=='O' && visited[i][j]!=1)
                    {
                        dfs(i,j,q,visited,board);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && visited[i][j]!=1)
                {
                    board[i][j]='X';
                    visited[i][j]=1;
                }
            }
        }
    }
};