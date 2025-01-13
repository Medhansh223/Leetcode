class Solution {
public:
    int minimumLength(string s) {
        map<char,int>mpp;
        for(auto it:s)
        {
            mpp[it]++;
        }
        int ans=0;
        for(auto it:mpp)
        {
            int freq = it.second;
            while(freq >= 3)
            {
                freq=freq-2;
            }
            ans=ans+freq;
        }
        return ans;
    }
};