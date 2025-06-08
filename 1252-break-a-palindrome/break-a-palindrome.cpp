class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        for(int i=0;i<n/2;i++)
        {
            if(palindrome[i]!='a')
            {
                palindrome[i]='a';
                return palindrome;
            }
        }
        if(n==1)
        {
            palindrome="";
        }
        else
        {
            palindrome[n-1]='b';
        }
        return palindrome;
    }
};