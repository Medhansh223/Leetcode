class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        map<long long, long long>mpp;
        for(int i=0;i<n;i++)
        {
            long long num = (i-nums[i]);
            mpp[num]++;
        }
        long long good = 0;
        for(auto it:mpp)
        {
            long long freq = it.second;
            good = good + (freq*(freq-1))/2;
        }
        long long bad = (long long)n*(n-1)/2 - good;
        return bad;
    }
};