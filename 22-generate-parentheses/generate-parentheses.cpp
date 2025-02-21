class Solution {
public:
    vector<string>result;
    void find(string& s, int n, int open, int close)
    {
        if(s.length() == 2*n)
        {
            result.push_back(s);
            return;
        }
        if(close > open)
        {
            return;
        }
        if(open > n)
        {
            return;
        }
        if(open < n)
        {
            s.push_back('(');
            find(s,n,open+1,close);
            s.pop_back();
        }
        if(close < open)
        {
            s.push_back(')');
            find(s,n,open,close+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        int open = 0;
        int close = 0;
        find(s,n,open,close);
        return result;
    }
};