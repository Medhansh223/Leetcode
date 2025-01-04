class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char,pair<int,int>>mpp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(mpp.find(s[i])==mpp.end())
            {
                mpp[s[i]]={i,i};
            }
            else
            {
                mpp[s[i]].second=i;
            }
        }
        int count=0;
        for(auto it: mpp)
        {
            int first=it.second.first;
            int last=it.second.second;
            if(first<last)
            {
                set<char>st;
                for(int i=first+1;i<last;i++)
                {
                    st.insert(s[i]);
                }
                count=count+st.size();
            }
        }
        return count;
    }
};