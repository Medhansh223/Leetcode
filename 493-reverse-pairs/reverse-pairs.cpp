class Solution {
public:
    void merge(int low, int mid, int high, vector<int>& nums)
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
        while(left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=0;i<temp.size();i++)
        {
            nums[i+low] = temp[i];
        }
    }
    int count_reverse_pairs(int low, int mid, int high, vector<int>& nums)
    {
        int count = 0;
        int right = mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(right <= high && (long long) nums[i] > 2LL * nums[right])
            {
                right++;
            }
            count = count + (right - (mid+1));
        }
        return count;
    }
    int mergesort(int low, int high, vector<int>& nums)
    {
        int count = 0;
        if(low >= high)
        {
            return count;
        }
        int mid = (low + high) / 2;
        count = count + mergesort(low,mid,nums);
        count = count + mergesort(mid+1,high,nums);
        count = count + count_reverse_pairs(low,mid,high,nums);
        merge(low,mid,high,nums);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(0,n-1,nums);
    }
};