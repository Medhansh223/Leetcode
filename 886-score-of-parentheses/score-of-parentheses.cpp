class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();
        int score=0;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            int value=0;
            if(s[i]=='(')
            {
                st.push(0);
            }
            else
            {
                while(st.top()!=0)
                {
                    int x=st.top();
                    value=value+x;
                    st.pop();
                }
                value=max(1,2*value);
                st.pop();
                st.push(value);
            }
        }
        while(!st.empty())
        {
            int y=st.top();
            score=score+y;
            st.pop();
        }
        return score;
    }
};