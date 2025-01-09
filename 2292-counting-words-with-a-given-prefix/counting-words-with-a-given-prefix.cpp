class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        int n=words.size();
        int m=pref.size();
        for(auto it:words)
        {
            bool isprefix=true;
            for(int i=0;i<m;i++)
            {
                if(pref[i]!=it[i])
                {
                    isprefix=false;
                    break;
                }
            }
            if(isprefix==true)
            {
                count++;
            }
        }
        return count;
    }
};