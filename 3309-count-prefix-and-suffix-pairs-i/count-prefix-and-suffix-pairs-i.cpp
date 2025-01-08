class Solution {
public:
    bool isvalidprefix(string& word1, string& word2)
    {
        int n=word1.size();
        int m=word2.size();
        if(n>m)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            if(word1[i]!=word2[i])
            {
                return false;
            }
        }
        return true;
    }
    bool isvalidsuffix(string& word1, string& word2)
    {
        int n=word1.size();
        int m=word2.size();
        if(n>m)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            if(word1[n-1-i]!=word2[m-1-i])
            {
                return false;
            }
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isvalidprefix(words[i],words[j]) && isvalidsuffix(words[i],words[j]))
                {
                    count++;
                }
            }
        }
        return count;
    }
};