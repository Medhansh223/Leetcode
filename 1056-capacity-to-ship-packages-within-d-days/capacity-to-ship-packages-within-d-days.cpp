class Solution {
public:
    int func(vector<int>& weights, int weight)
    {
        int day = 1;
        int load = 0;
        int n = weights.size();
        for(int i=0;i<n;i++)
        {
            if(load + weights[i] > weight)
            {
                day++;
                load = weights[i];
            }
            else
            {
                load = load + weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,weights[i]);
            sum = sum + weights[i];
        }
        int low = maxi;
        int high = sum;
        int ans = sum;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int day = func(weights,mid);
            if(day<=days)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};