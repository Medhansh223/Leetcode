class Solution {
public:
    void find(int indx, int k, int n, vector<vector<int>>& result, vector<int>& ans)
    {
        if(k==0 && n==0)
        {
            result.push_back(ans);
            return;
        }
        if(k==0 || n==0)
        {
            return;
        }
        for(int i=indx;i<=9;i++)
        {
            ans.push_back(i);
            find(i+1,k-1,n-i,result,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        vector<int>ans;
        find(1,k,n,result,ans);
        return result;
    }
};