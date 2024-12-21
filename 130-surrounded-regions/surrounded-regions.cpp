class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        visited[row][col] = 1;

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && visited[nrow][ncol] != 1) {
                dfs(nrow, ncol, visited, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Traverse the first and last rows
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && visited[0][j] != 1) {
                dfs(0, j, visited, board);
            }
            if (board[n-1][j] == 'O' && visited[n-1][j] != 1) {
                dfs(n-1, j, visited, board);
            }
        }

        // Traverse the first and last columns
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && visited[i][0] != 1) {
                dfs(i, 0, visited, board);
            }
            if (board[i][m-1] == 'O' && visited[i][m-1] != 1) {
                dfs(i, m-1, visited, board);
            }
        }

        // Convert all unvisited 'O's to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && visited[i][j] != 1) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
