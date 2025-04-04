class Solution {
public:
int binary(int low,int high,vector<int>&nums,int &target)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(nums[mid]>target)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return binary(0,n-1,nums,target);
    }
};