class Solution {
public:
    void dfs(string beginWord, string word, vector<vector<string>>& result, vector<string>& seq, unordered_map<string,int>& mpp)
    {
        if(word == beginWord)
        {
            reverse(seq.begin(),seq.end());
            result.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps = mpp[word];
        for(int i=0; i < word.size(); i++)
        {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(beginWord, word, result, seq, mpp);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        queue<string>q;
        q.push(beginWord);
        unordered_map<string,int>mpp;
        mpp[beginWord] = 1;
        while(!q.empty())
        {
            string word = q.front();
            q.pop();
            int steps = mpp[word];
            if(word == endWord)
            {
                break;
            }
            for(int i=0; i < word.size(); i++)
            {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if(st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        vector<vector<string>>result;
        if(mpp.find(endWord) != mpp.end())
        {
            vector<string>seq;
            seq.push_back(endWord);
            dfs(beginWord,endWord,result,seq,mpp);
        }
        return result;
    }
};