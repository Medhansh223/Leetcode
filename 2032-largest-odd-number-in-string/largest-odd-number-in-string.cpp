class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        for(int i=n-1;i>=0;i--)
        {
            int x = num[i];
            if(x % 2 == 1)
            {
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};