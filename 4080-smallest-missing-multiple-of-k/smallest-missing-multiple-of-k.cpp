class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        for(int i=k;;i+=k)
        {
            if(st.find(i) == st.end())
            {
                return i;
            }
        }
        return -1;
    }
};