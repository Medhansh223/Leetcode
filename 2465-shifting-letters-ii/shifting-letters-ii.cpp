class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int>diff(n+1,0);
        for(auto it:shifts)
        {
            int start=it[0];
            int end=it[1];
            int direction=it[2];
            if(direction==1)
            {
                diff[start]++;
                diff[end+1]--;
            }
            else
            {
                diff[start]--;
                diff[end+1]++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            diff[i]=diff[i]+diff[i-1];
        }
        string res;
        for(int i=0;i<n;i++)
        {
            int count=diff[i]%26;
            if(count<0)
            {
                count=count+26;
            }
            char c=s[i];
            c='a'+(c-'a'+count)%26;
            res.push_back(c);
        }
        return res;
    }
};