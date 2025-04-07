class Solution {
public:
    long long fun(vector<int>&quantities,int mid)
    {
        int n=quantities.size();
        long long total=0;
        for(int i=0;i<quantities.size();i++)
        {
            total=total+(long long)ceil((double)quantities[i]/mid);
        }
        return total;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int N=n;
        n=quantities.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,quantities[i]);
        }
        int low=1;
        int high=maxi;
        int ans=n;
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long total=fun(quantities,mid);
            if(total<=N)
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