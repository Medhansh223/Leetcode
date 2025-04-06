class Solution {
public:
    long long fun(vector<int>&nums,int divi)
    {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+(long long)ceil((double)nums[i]/divi);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
        }
        int low=1;
        int high=maxi;
        int ans=maxi;
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long sum=fun(nums,mid);
            if(sum<=threshold)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};