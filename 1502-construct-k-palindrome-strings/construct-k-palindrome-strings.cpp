class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        if(n<k)
        {
            return false;
        }
        map<char,int>mpp;
        for(auto c:s)
        {
            mpp[c]++;
        }
        int oddcount=0;
        for(auto it:mpp)
        {
            int freq=it.second;
            if(freq % 2 == 1)
            {
                oddcount++;
            }
        }
        if(oddcount>k)
        {
            return false;
        }
        return true;
    }
};