class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int element=-1;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                count++;
                element=nums[i];
            }
            else if(nums[i]==element)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        int count1=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==element)
            {
                count1++;
            }
        }
        if(count1>(n/2))
        {
            return element;
        }
        return -1;
    }
};