class Solution {
public:
    long long fun(vector<int>&piles,int hours)
    {
        long long total=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            total=total+(long long)ceil((double)piles[i]/hours);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,piles[i]);
        }
        int low=1;
        int high=maxi;
        int ans=high;
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long total=fun(piles,mid);
            if(total<=h)
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