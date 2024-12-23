class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<vector<int>>& image, int sr, int sc, int color, int& initial)
    {
        int n=image.size();
        int m=image[0].size();
        ans[sr][sc]=color;
        vector<int>drow={-1,0,+1,0};
        vector<int>dcol={0,+1,0,-1};
        for(int i=0;i<4;i++)
        {
            int row=sr+drow[i];
            int col=sc+dcol[i];
            if(row>=0 && row<n && col>=0 && col<m && image[row][col]==initial && ans[row][col]!=color)
            {                   
                dfs(ans,image,row,col,color,initial);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int initial=image[sr][sc];
        vector<vector<int>>ans=image;
        dfs(ans,image,sr,sc,color,initial);
        return ans;
    }
};