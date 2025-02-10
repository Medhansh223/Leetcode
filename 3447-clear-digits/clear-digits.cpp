class Solution {
public:
    bool check(char c)
    {
        if(c>='0' && c<='9')
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    string clearDigits(string s) {
        int n = s.size();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            int c = s[i];
            if(check(c))
            {
                st.push(c);
            }
            else
            {
                st.pop();
            }
        }
        string result = "";
        while(!st.empty())
        {
            char c = st.top();
            st.pop();
            result = result + c;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};