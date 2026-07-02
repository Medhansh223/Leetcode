class Solution {
public:
    void find(int ind, int target, vector<int>& candidates, vector<vector<int>>& result, vector<int>& ans)
    {
        if(target == 0)
        {
            result.push_back(ans);
            return;
        }
        for(int i=ind;i<candidates.size();i++)
        {
            if(i>ind && candidates[i] == candidates[i-1])
            {
                continue;
            }
            if(candidates[i] <= target)
            {
                ans.push_back(candidates[i]);
                find(i+1,target-candidates[i],candidates,result,ans);
                ans.pop_back();
            }
        } 
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ans;
        vector<vector<int>>result;
        find(0,target,candidates,result,ans);
        return result;
    }
};