class Solution {
public:
    void bfs(vector<vector<int>>& ans, vector<vector<int>>& image, int sr, int sc, int color, int& initial)
    {
        int n=image.size();
        int m=image[0].size();
        ans[sr][sc]=color;
        vector<int>drow={-1,0,+1,0};
        vector<int>dcol={0,+1,0,-1};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row<n && col>=0 && col<m && image[row][col]==initial && ans[row][col]!=color)
                {
                    q.push({row,col});
                    ans[row][col]=color;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int initial=image[sr][sc];
        vector<vector<int>>ans=image;
        bfs(ans,image,sr,sc,color,initial);
        return ans;
    }
};