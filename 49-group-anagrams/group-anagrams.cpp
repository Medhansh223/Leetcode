class Solution {
public:
    string generate(string &str)
    {
        vector<int>freq(26,0);
        for(int i=0;i<str.size();i++)
        {
            char ch = str[i];
            freq[ch - 'a']++;
        }
        string word = "";
        for(int i=0;i<26;i++)
        {
            int frequency = freq[i];
            if(frequency > 0)
            {
                word = word + string(frequency,i + 'a');
            }
        }
        return word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        map<string,vector<string>>mpp;
        int n = strs.size();
        for(int i=0;i<n;i++)
        {
            string str = strs[i];
            string word = generate(str);
            mpp[word].push_back(str);
        }
        for(auto it:mpp)
        {
            result.push_back(it.second);
        }
        return result;
    }
};