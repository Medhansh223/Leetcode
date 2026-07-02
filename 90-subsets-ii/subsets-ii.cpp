class Solution {
public:
    void recurr(vector<vector<int>>&result,vector<int>&nums,int i,vector<int>&temp)
    {
        result.push_back(temp);
        for(int j=i;j<nums.size();j++)
        {
            if(i!=j && nums[j]==nums[j-1])//duplicacy
            {
                continue;
            }
            temp.push_back(nums[j]);
            recurr(result,nums,j+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>result;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        recurr(result,nums,0,temp);
        return result;
    }
};