class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int>st;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }
        vector<int>result;
        for(int i=mini;i<=maxi;i++)
        {
            if(st.find(i) == st.end())
            {
                result.push_back(i);
            }
        }
        return result;
    }
};