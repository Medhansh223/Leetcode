class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n!=m)
        {
            return false;
        }
        map<char,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[s1[i]]++;
        }
        for(int i=0;i<m;i++)
        {
            if(mpp.find(s2[i])==mpp.end())
            {
                return false;
            }
        }
        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s2[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mp.find(s1[i])==mp.end())
            {
                return false;
            }
        }
        for(auto it:mpp)
        {
            char st = it.first;
            if(mpp[st]!=mp[st])
            {
                return false;
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                count++;
            }
            if(count>2)
            {
                return false;
            }
        }
        return true;
    }
};