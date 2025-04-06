class Solution {
public:
    long long fun(vector<int>&candies,int mid)
    {
        int n=candies.size();
        long long total=0;
        for(int i=0;i<n;i++)
        {
            total=total+(long long)floor((long long)candies[i]/mid);
        }
        return total;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,candies[i]);
        }
        int low=1;
        int high=maxi;
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long total=fun(candies,mid);
            if(total>=k)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};