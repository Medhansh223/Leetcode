class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>freq;
        int start = 0;
        int e = 0;
        int maxlength = 0;
        while(e < n)
        {
            freq[s[e]]++;
            while(freq[s[e]] > 2)
            {
                freq[s[start]]--;
                start++;
            }
            maxlength = max(maxlength,e-start+1);
            e++;
        }
        return maxlength;
    }
};