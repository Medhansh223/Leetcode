class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>>result;
        if(n==0)
        {
            return {};
        }
        if(n==1)
        {
            result.push_back({1});
            return result;
        }
        if(n==2)
        {
            result.push_back({1});
            result.push_back({1,1});
            return result;
        }
        result.push_back({1});
        result.push_back({1,1});
        for(int i=2;i<n;i++)
        {
            vector<int>ans;
            ans.push_back(1);
            for(int j=1;j<i;j++)
            {
                int num=result[i-1][j]+result[i-1][j-1];
                ans.push_back(num);
            }
            ans.push_back(1);
            result.push_back(ans);
        }
        return result;
    }
};