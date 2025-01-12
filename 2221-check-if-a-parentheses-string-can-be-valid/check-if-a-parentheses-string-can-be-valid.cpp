class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n % 2 == 1)
        {
            return false;
        }
        int wildcard=0;
        int opening=0;
        int closing=0;
        for(int i=0;i<n;i++)
        {
            if(locked[i]=='0')
            {
                wildcard++;
            }
            else if(s[i]=='(')
            {
                opening++;
            }
            else
            {
                closing++;
            }
            if(wildcard < (closing - opening))
            {
                return false;
            }
        }
        opening=closing=wildcard=0;
        for(int i=n-1;i>0;i--)
        {
            if(locked[i]=='0')
            {
                wildcard++;
            }
            else if(s[i]=='(')
            {
                opening++;
            }
            else
            {
                closing++;
            }
            if(wildcard < (opening - closing))
            {
                return false;
            }
        }
        return true;
    }
};