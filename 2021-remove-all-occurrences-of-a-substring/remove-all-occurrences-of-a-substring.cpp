class Solution {
public:
    bool check(stack<char>& st, string part, int m)
    {
        stack<char>temp = st;
        for(int i=m-1;i>=0;i--)
        {
            char c = temp.top();
            if(c != part[i])
            {
                return false;
            }
            temp.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        stack<char>st;
        int n = s.length();
        int m = part.length();
        for(int i=0;i<n;i++)
        {
            char c = s[i];
            st.push(c);
            if(st.size() >= m && check(st,part,m)==true)
            {
                for(int j=0;j<m;j++)
                {
                    st.pop();
                }
            }
        }
        string result="";
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