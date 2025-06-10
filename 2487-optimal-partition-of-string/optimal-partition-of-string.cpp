class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        vector<int>num(26,-1);
        int count = 0;
        int curr = 0;
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if(num[ch - 'a'] >= curr)
            {
                count++;
                curr = i;
            }
            num[ch - 'a'] = i;
        }
        count++;
        return count;
    }
};