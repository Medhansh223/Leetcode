class Solution {
public:
    vector<string>result;
    bool isValid(string& s)
    {
        int n = s.length();
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count < 0)
            {
                return false;
            }
        }
        if(count == 0)
        {
            return true;
        }
        return false;
    }
    void find(string& s, int n)
    {
        if(s.length() == 2*n)
        {
            if(isValid(s) == true)
            {
                result.push_back(s);
            }
            return;
        }
        s.push_back('(');
        find(s,n);
        s.pop_back();
        s.push_back(')');
        find(s,n);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        find(s,n);
        return result;
    }
};