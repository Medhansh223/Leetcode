class Solution {
public:
    int lower(vector<int>&nums,int target)
    {
        int low=0;
        int n=nums.size();

        int high=n-1;
        int ans=n;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>=target)
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
    int upper(vector<int>&nums,int target)
    {
        int low=0;
        int n=nums.size();
        int high=n-1;
        int ans=n;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>target)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans-1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=lower(nums,target);
        if(first==n || nums[first]!=target)
        {
            return {-1,-1};
        }
        int last=upper(nums,target);
        return {first,last};
    }
};