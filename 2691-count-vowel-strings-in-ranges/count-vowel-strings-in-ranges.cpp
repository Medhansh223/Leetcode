class Solution {
public:
    bool vowels(char &ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        {
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>cumm(n,0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(vowels(words[i][0]) && vowels(words[i].back()))
            {
                sum++;
            }
            cumm[i]=sum;
        }
        int m=queries.size();
        vector<int>result(m,0);
        for(int i=0;i<m;i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            result[i]=cumm[r]-((l>0) ? cumm[l-1] : 0);
        }
        return result;
    }
};