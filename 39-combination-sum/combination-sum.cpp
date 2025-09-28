class Solution {
public:
    void combo(int ind,vector<int>&candidates,int target,vector<vector<int>>&result,vector<int>&ans)
    {
        int n=candidates.size();
        if(ind==n)
        {
            if(target==0)
            {
                result.push_back(ans);
            }
            return;
        }
        if(candidates[ind]<=target)
        {
            ans.push_back(candidates[ind]);
            combo(ind,candidates,target-candidates[ind],result,ans);
            ans.pop_back();
        }
        combo(ind+1,candidates,target,result,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>result;
        vector<int>ans;
        combo(0,candidates,target,result,ans);
        return result;
    }
};