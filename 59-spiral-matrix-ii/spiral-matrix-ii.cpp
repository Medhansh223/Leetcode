class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;
        int j=1;
        vector<vector<int>>mat(n,vector<int>(n,0));
        while(left <= right && top <= bottom)
        {
            for(int i=left;i<=right;i++)
            {
                mat[top][i] = j;
                j++;
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                mat[i][right] = j;
                j++;
            } 
            right--;
            if(top <= bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    mat[bottom][i] = j;
                    j++;
                }
                bottom--;
            }
            if(left <= right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    mat[i][left] = j;
                    j++;
                }
                left++;
            }
        }
        return mat;
    }
};