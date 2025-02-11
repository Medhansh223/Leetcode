class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.length();
        int m = part.length();
        string result = "";
        for(auto ch:s)
        {
            result = result + ch;
            if(result.length() >= m && result.substr(result.length() - m) == part)
            {
                result.erase(result.length() - m);
            }
        }
        return result;
    }
};