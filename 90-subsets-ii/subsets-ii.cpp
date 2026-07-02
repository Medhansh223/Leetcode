class Solution {
public:
    void func(set<vector<int>>& st, vector<int>& temp, vector<int>& nums, int i)
    {
        if(i == nums.size())
        {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        func(st,temp,nums,i+1);
        temp.pop_back();
        func(st,temp,nums,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<int>temp;
        func(st,temp,nums,0);
        vector<vector<int>>result(st.begin(),st.end());
        return result;
    }
};