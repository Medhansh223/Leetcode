class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<vector<int>>mat(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            mat[i][i]=0;
        }
        for(auto it:prerequisites)
        {
            int u=it[0];
            int v=it[1];
            mat[u][v]=1;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(mat[i][k]!=INT_MAX && mat[k][j]!=INT_MAX)
                    {
                        mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
                    }
                }
            }
        }
        vector<bool>ans;
        for(auto it:queries)
        {
            int u=it[0];
            int v=it[1];
            if(mat[u][v]!=INT_MAX)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};