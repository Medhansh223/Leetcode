class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        int n=nums.size();
        int subsets=1<<n;
        for(int num=0;num<subsets;num++)
        {
            vector<int>list;
            for(int i=0;i<n;i++)
            {
                if(num & (1<<i))
                {
                    list.push_back(nums[i]);
                }
            }
            result.push_back(list);
        }
        return result;
    }
};