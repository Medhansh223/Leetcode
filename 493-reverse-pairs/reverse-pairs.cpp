class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high)
    {
        vector<int>temp;
        int left = low;
        int right = mid+1;
        while(left <= mid && right <= high) 
        {
            if(nums[left] <= nums[right]) 
            {
                temp.push_back(nums[left]);
                left++;
            }
            else 
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= mid) 
        {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high) 
        {
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=0;i<temp.size();i++)
        {
            nums[i+low] = temp[i];
        }
    }
    int countPairs(vector<int>& nums, int low, int mid, int high)
    {
        int right = mid + 1;
        int count = 0;
        for(int i=low;i<=mid;i++) 
        {
            while (right <= high && (long long) nums[i] > 2LL * nums[right]) 
            {
                right++;
            }
            count += (right - (mid + 1));
        }
        return count;
    }
    int mergesort(vector<int>& nums, int low, int high)
    {
        int count = 0;
        if(low >= high){
            return count;
        }
        int mid = (low + high)/2;
        count = count + mergesort(nums,low,mid);
        count = count + mergesort(nums,mid+1,high);
        count = count + countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums,0,n-1);
    }
};