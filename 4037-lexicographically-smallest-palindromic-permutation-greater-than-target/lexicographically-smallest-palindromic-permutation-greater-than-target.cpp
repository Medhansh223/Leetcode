class Solution {
public:
    string result = "";
    char oddchr = '$';
    int halflen = 0;
    bool solve(string& curr, vector<int>& count, string target, int i, bool greater)
    {
        if(curr.length() == halflen)
        {
            string a = curr;
            string b = curr;
            reverse(b.begin(),b.end());
            if(oddchr != '$')
            {
                a = a + oddchr;
            }
            a = a + b;
            if(a > target)
            {
                result = a;
                return true;
            }
            return false;
        }

        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            if(count[ch-'a'] == 0)
            {
                continue;
            }
            if(greater == false && ch < target[i])
            {
                continue;
            }
            curr.push_back(ch);
            count[ch-'a']--;
            bool isgreater = greater || ch > target[i];
            if(solve(curr, count, target, i+1, isgreater) == true)
            {
                return true;
            }
            curr.pop_back();
            count[ch-'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        vector<int>count(26,0);
        for(char ch : s)
        {
            count[ch-'a']++;        
        }
        int oddcount = 0;
        for(int i=0;i<26;i++)
        {
            if(count[i] % 2 == 1)
            {
                oddcount++;
                oddchr = i + 'a';
            }
        }
        if(oddcount > 1)
        {
            return "";
        }
        for(int i=0;i<26;i++)
        {
            count[i] = count[i]/2;
        }
        halflen = s.length() / 2;
        string curr;
        solve(curr,count,target,0,false);
        return result;
    }
};