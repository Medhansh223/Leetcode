class Solution {
public:
    bool kmp(string &pattern,string &text)
    {
        int m=pattern.size();
        int n=text.size();
        vector<int>lps=buildlps(pattern);
        int i=0;
        int j=0;
        while(i<n)
        {
            if(pattern[j]==text[i])
            {
                i++;
                j++;
            }
            if(j==m)
            {
                return true;
            }
            else if(i<n && pattern[j]!=text[i])
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return false;
    }
    vector<int>buildlps(string &pattern)
    {
        int n=pattern.size();
        int len=0;
        vector<int>lps(n,0);
        int i=1;
        while(i<n)
        {
            if(pattern[i]==pattern[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                {
                    len=lps[len-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string>result;
        sort(words.begin(),words.end(),[](const string &a,const string &b)
        {
            return a.size()<b.size();
        });
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(kmp(words[i],words[j]))
                {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};