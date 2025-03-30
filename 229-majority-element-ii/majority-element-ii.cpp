class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int element1;
        int element2;
        for(int i=0;i<n;i++)
        {
            if(count1 == 0 && element2 != nums[i])
            {
                count1 = 1;
                element1 = nums[i];
            }
            else if(nums[i] == element1)
            {
                count1++;
            }
            else if(count2 == 0 && element1 != nums[i])
            {
                count2 = 1;
                element2 = nums[i];
            }
            else if(nums[i] == element2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int>result;
        count1=0;
        for(int i=0;i<n;i++)
        {
            if(element1 == nums[i])
            {
                count1++;
            }
        }
        if(count1 > (n/3))
        {
            result.push_back(element1);
        }
        count2=0;
        for(int i=0;i<n;i++)
        {
            if(element2 == nums[i])
            {
                count2++;
            }
        }
        if(count2 > (n/3))
        {
            result.push_back(element2);
        }
        return result;
    }
};