class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char>minchar(n);
        minchar[n-1] = s[n-1];
        for(int i=n-2;i>=0;i--)
        {
            minchar[i] = min(s[i],minchar[i+1]);
        }
        string t = "";
        string res = "";
        int i = 0;
        while(i < n)
        {
            t.push_back(s[i]);
            char mini;
            if(i+1 < n)
            {
                mini = minchar[i+1];
            }
            else
            {
                mini = s[i];
            }
            while(!t.empty() && t.back() <= mini)
            {
                res.push_back(t.back());
                t.pop_back();
            }
            i++;
        }
        while(!t.empty())
        {
            res.push_back(t.back());
            t.pop_back();
        }
        return res;
    }
};