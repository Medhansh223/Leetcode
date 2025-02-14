class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<priority_queue<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                adj[i-j].push(grid[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                priority_queue<int>&pq=adj[i-j];
                int num=pq.top();
                pq.pop();
                grid[i][j]=num;
            }
        }  
        vector<priority_queue<int,vector<int>,greater<int>>>ad(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                {
                    ad[j-i].push(grid[i][j]);
                }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                priority_queue<int,vector<int>,greater<int>>&pq=ad[j-i];
                int num=pq.top();
                pq.pop();
                grid[i][j]=num;
            }
        }
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    {
                        cout<<grid[i][j]<<" ";
                    }
                cout<<endl;
            }
        return grid;
    }
};