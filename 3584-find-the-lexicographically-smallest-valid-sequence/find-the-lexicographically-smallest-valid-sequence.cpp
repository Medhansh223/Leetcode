class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>rightmatch(n,0);
        int matched = 0;
        int i = n-1;
        int j = m-1;
        while(i >= 0)
        {
            if(j >= 0 && word1[i] == word2[j])
            {
                matched++;
                j--;
            }
            rightmatch[i] = matched;
            i--;
        }
        vector<int>seq;
        i = 0;
        j = 0;
        bool change = true;
        while(i < n && j < m)
        {
            if(word1[i] == word2[j])
            {
                seq.push_back(i);
                j++;
            }
            else if(change == true && i+1 < n && rightmatch[i+1] >= m-j-1)
            {
                seq.push_back(i);
                j++;
                change = false;
            }
            i++;
        }
        if(j == m)
        {
            return seq;
        }
        else
        {
            return vector<int>();
        }
    }
};