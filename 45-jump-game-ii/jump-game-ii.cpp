class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int coverage=0;
        int last=0;
        int total=0;
        int destination=n-1;
        if(n==1)
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            coverage=max(coverage,nums[i]+i);
            if(last==i)
            {
                total++;
                last=coverage;
                if(coverage>=destination)
                {
                    return total;
                }
            }
        }
        return -1;
    }
};