#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitsum(int num)
    {
        int sum = 0;
        int rem = 0;
        while(num > 0)
        {
            rem = num % 10;
            sum = sum + rem;
            num = num / 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int maxsum = -1;
        map<int, int> mpp;
        for(int i=0;i<n;i++)
        {
            int num = nums[i];
            int sum = digitsum(num);
            if(mpp.find(sum) != mpp.end())
            {
                maxsum = max(maxsum, num + mpp[sum]);
                mpp[sum] = max(mpp[sum], num);
            }
            else
            {
                mpp[sum] = num;
            }
        }
        return maxsum;
    }
};