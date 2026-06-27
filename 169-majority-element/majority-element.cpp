class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>freq;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        for(auto it:freq)
        {
            int first = it.first;
            int second = it.second;
            if(second  > (n/2))
            {
                return first;
            }
        }
        return -1;
    }
};