class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        int right=0;
        int maxlen=0;
        int len=0;
        map<char,int>mpp;
        while(right<n)
        {
            if(mpp.find(s[right])!=mpp.end())
            {
                if(mpp[s[right]]>=left)
                {
                    left=mpp[s[right]]+1;
                }
            }
            len=right-left+1;
            maxlen=max(maxlen,len);
            mpp[s[right]]=right;
            right++;
        }
        return maxlen;
    }
};