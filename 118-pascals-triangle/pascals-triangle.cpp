class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>triangle;
        int n=numRows;
        for(int i=0;i<n;i++)
        {
            vector<int>rows(i+1,1);
            for(int j=1;j<i;j++)
            {
                rows[j]=triangle[i-1][j-1]+triangle[i-1][j];
            }
            triangle.push_back(rows);
        }
        return triangle;
    }
};