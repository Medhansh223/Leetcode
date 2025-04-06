class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3)
        {
            return false;
        }
        int low=1;
        int high=n-2;
        int peak=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                peak=mid;
                break;
            }
            if(arr[mid]>arr[mid-1])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(peak==-1)
        {
            return false;
        }
        for(int i=0;i<peak;i++)
        {
            if(arr[i]>=arr[i+1])
            {
                return false;
            }
        }
        for(int i=n-1;i>peak;i--)
        {
            if(arr[i]>=arr[i-1])
            {
                return false;
            }
        }
        return peak;
    }
};