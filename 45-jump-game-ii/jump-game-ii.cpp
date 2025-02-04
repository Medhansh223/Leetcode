class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int maxi = 0;
        int lastindex = 0;
        if(n==1)
        {
            return 0;
        }
        int destination = n-1;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,i+nums[i]);
            if(i==lastindex)
            {
                lastindex = maxi;
                jumps++; 
            }
            if(lastindex>=destination)
            {
                return jumps;
            }
        }
        return jumps;
    }
};