class Solution {
public:
    string generate(string& str)
    {
        vector<int>hash(26,0);
        int n = str.length();
        for(int i=0;i<n;i++)
        {
            char ch = str[i];
            hash[ch - 'a']++;
        }
        string word = "";
        for(int i=0;i<26;i++)
        {
            int freq = hash[i];
            if(freq > 0)
            {
                word = word + string(freq,i + 'a');
            }
        }
        return word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<string,vector<string>>mpp;
        vector<vector<string>>result;
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