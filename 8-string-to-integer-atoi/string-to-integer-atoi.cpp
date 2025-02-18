class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        bool sign = true;
        int num = 0;
        int i = 0;
        while(i < n && s[i] == ' ')
        {
            i++;
        }
        if(i < n && (s[i] == '-' || s[i] == '+'))
        {
            if(s[i] == '-')
            {
                sign = false;
            }
            i++;
        }
        while(i < n)
        {
            if(!isdigit(s[i]))
            {
                break;
            }
            else
            {
                int digit = s[i] - '0';
                if(num > (INT_MAX - digit)/10)
                {
                    if(sign == true)
                    {
                        return INT_MAX;
                    }
                    else
                    {
                        return INT_MIN;
                    }
                }
                num = num * 10 + digit;
                i++;
            }
        }
        if(sign == true)
        {
            return num;
        }
        else
        {
            return -num;
        }
    }
};