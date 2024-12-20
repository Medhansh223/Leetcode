class Solution {
public:
    void bfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>>& image, int color, int row[], int col[], int initial)
    {
        ans[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+row[i];
                int ncol=c+col[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initial && ans[nrow][ncol]!=color)
                {
                    q.push({nrow,ncol});
                    ans[nrow][ncol]=color;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial=image[sr][sc];
        vector<vector<int>>ans=image;
        int row[]={-1,0,+1,0};
        int col[]={0,+1,0,-1};
        bfs(sr,sc,ans,image,color,row,col,initial);
        return ans;
    }
};