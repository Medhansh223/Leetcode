class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 1;
        set<int>st;
        if(n == 0)
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        for(auto it:st)
        {
            if(st.find(it-1) == st.end())
            {
                int count = 1;
                int x = it;
                while(st.find(x+1) != st.end())
                {
                    count++;
                    x++;
                }
                longest = max(longest,count);
            }
        }
        return longest;
    }
};