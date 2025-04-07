class Solution {
public:
    long long int func(vector<int>& bloomDay, long long int day, long long int m, long long int k)
    {
        int n=bloomDay.size();
        long long int count=0;
        long long int blooms=0;
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=day)
            {
                count++;
            }
            else
            {
                blooms=blooms+(long long int)floor((count/k));
                count=0;
            }
        }
        blooms=blooms+(long long int)floor((count/k));
        return blooms;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<(long long int)m*k)
        {
            return -1;
        }
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low=mini;
        int high=maxi;
        int ans=maxi;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int bloom = func(bloomDay,mid,m,k);
            if(bloom>=m)
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