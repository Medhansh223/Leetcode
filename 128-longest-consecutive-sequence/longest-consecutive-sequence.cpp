class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int longest = 1;
        int count = 0;
        int last = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(nums[i] - 1 == last)
            {
                count++;
            }
            else if(nums[i] != last)
            {
                count = 1;
            }
            last = nums[i];
            longest = max(longest,count);
        }
        return longest;
    }
};