class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>>& image, int color, int row[], int col[], int initial)
    {
        ans[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=sr+row[i];
            int ncol=sc+col[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initial && ans[nrow][ncol]!=color)
            {
                dfs(nrow,ncol,ans,image,color,row,col,initial);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial=image[sr][sc];
        vector<vector<int>>ans=image;
        int row[]={-1,0,+1,0};
        int col[]={0,+1,0,-1};
        dfs(sr,sc,ans,image,color,row,col,initial);
        return ans;
    }
};