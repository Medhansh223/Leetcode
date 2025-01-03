class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>rightsum(n);
        long long rsum=0;
        for(int i=0;i<n;i++)
        {
            rsum=rsum+nums[i];
            rightsum[i]=rsum;
        }
        vector<long long>leftsum(n);
        long long lsum=0;
        for(int i=n-1;i>=0;i--)
        {
            lsum=lsum+nums[i];
            leftsum[i]=lsum;
        }
        int i=0;
        int j=1;
        int count=0;
        while(i<n && j<n)
        {
            if(rightsum[i]>=leftsum[j])
            {
                count++;
            }
            i++;
            j++;
        }
        return count;
    }
};