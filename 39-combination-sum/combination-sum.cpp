class Solution {
public:
    void combo(int indx, vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& ans)
    {
        int n = candidates.size();
        if(indx == n)
        {
            if(target == 0)
            {
                result.push_back(ans);
            }
            return;
        }
        if(candidates[indx] <= target)
        {
            ans.push_back(candidates[indx]);
            combo(indx,candidates,target - candidates[indx],result,ans);
            ans.pop_back();
        }
        combo(indx + 1,candidates,target,result,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>ans;
        combo(0,candidates,target,result,ans);
        return result;
    }
};