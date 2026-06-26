class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        result.push_back({1});
        for(int i=1;i<numRows;i++)
        {
            vector<int>res;
            res.push_back(1);
            for(int j=1;j<i;j++)
            {
                int ans = result[i-1][j-1] + result[i-1][j];
                res.push_back(ans);
            }
            res.push_back(1);
            result.push_back(res);
        }
        return result;
    }
};