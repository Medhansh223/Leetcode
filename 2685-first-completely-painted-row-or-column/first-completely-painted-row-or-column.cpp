class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,pair<int,int>>mpp;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                int element=mat[i][j];
                mpp[element]={i,j};
            }
        }
        int s=arr.size();
        vector<int>rarr(n,0);
        vector<int>carr(m,0);
        for(int i=0;i<s;i++)
        {
            int element=arr[i];
            auto pos=mpp[element];
            int row=pos.first;
            int col=pos.second;
            rarr[row]++;
            carr[col]++;
            if(rarr[row]==m || carr[col]==n)
            {
                return i;
            }
        }
        return -1;
    }
};