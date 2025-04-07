class Solution {
public:
    bool fun(vector<int>&nums,int k, int mid)
    {
        int n=nums.size();
        int sum=0;
        int split=1;
        for(int i=0;i<n;i++)
        {
            if(sum+nums[i]<=mid)
            {
                sum=sum+nums[i];
            }
            else
            {
                split++;
                sum=nums[i];
                if(split>k)
                {
                    return false;
                }
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            sum=sum+nums[i];
        }
        int low=maxi;
        int high=sum;
        int ans=sum;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(fun(nums,k,mid))
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