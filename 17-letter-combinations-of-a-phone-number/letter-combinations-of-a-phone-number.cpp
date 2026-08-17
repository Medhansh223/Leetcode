class Solution {
public:
    void solve(int idx, vector<string>& result, string& temp, unordered_map<char,string>& mpp, string digits)
    {
        if(idx >= digits.length())
        {
            result.push_back(temp);
        }
        char ch = digits[idx];
        string str = mpp[ch];
        for(int i=0;i<str.size();i++)
        {
            temp.push_back(str[i]);
            solve(idx+1,result,temp,mpp,digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        if(digits.size() == 0)
        {
            return result;
        }
        unordered_map<char,string>mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        string temp = "";
        solve(0,result,temp,mpp,digits);
        return result;
    }
};