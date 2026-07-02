class Solution {
public:
    bool palindrome(int start, int end, string s)
    {
        while(start <= end)
        {
            if(s[start] == s[end])
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    void recurr(vector<vector<string>>& result, vector<string>& temp, int i, string s)
    {
        if(i == s.length())
        {
            result.push_back(temp);
            return;
        }
        for(int j=i;j<s.length();j++)
        {
            if(palindrome(i,j,s))
            {
                temp.push_back(s.substr(i,j-i+1));
                recurr(result,temp,j+1,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>temp;
        recurr(result,temp,0,s);
        return result;
    }
};