class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            freq[ch - 'a']++;
        }
        sort(freq.begin(),freq.end());
        int deletions = 0;
        for(int i=24;i>=0;i--)
        {
            if(freq[i] > 0 && freq[i] >= freq[i+1])
            {
                int prev = freq[i];
                freq[i] = max(0,freq[i+1] - 1);
                deletions = deletions + prev - freq[i];
            }
        }
        return deletions;
    }
};