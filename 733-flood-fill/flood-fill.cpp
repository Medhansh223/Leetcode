class Solution {
public:
    void bfs(vector<vector<int>>&image,vector<vector<int>>&copy,int sr,int sc,int initial,int color)
    {
        copy[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,+1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && copy[nrow][ncol]!=color && image[nrow][ncol]==initial)
                {
                    copy[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>copy=image;
        int initial=image[sr][sc];
        bfs(image,copy,sr,sc,initial,color);
        return copy;
    }
};