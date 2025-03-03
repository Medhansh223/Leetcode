class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans(n);
        int i = 0;
        int j = n-1;
        int k = 0;
        int l = n-1;
        while(i < n && j >= 0)
        {
            if(nums[i] < pivot)
            {
                ans[k] = nums[i];
                k++;
            }
            if(nums[j] > pivot)
            {
                ans[l] = nums[j];
                l--;
            }
            i++;
            j--;
        }
        while(k <= l)
        {
            ans[k] = pivot;
            k++;
        }
        return ans;
    }
};