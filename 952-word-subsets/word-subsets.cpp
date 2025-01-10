class Solution {
public:
    vector<int>countalphabet(string& str)
    {
        vector<int>ans(26,0);
        for(auto c:str)
        {
            ans[c-'a']++;
        }
        return ans;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>words2max(26,0);
        for(auto it:words2)
        {
            vector<int>words2count=countalphabet(it);
            for(int i=0;i<26;i++)
            {
                words2max[i]=max(words2max[i],words2count[i]);
            }
        }
        vector<string>ans;
        for(auto it:words1)
        {
            vector<int>words1count=countalphabet(it);
            bool subset=true;
            for(int i=0;i<26;i++)
            {
                if(words1count[i]<words2max[i])
                {
                    subset=false;
                    break;
                }
            }
            if(subset==true)
            {
                ans.push_back(it);
            }
        }
        return ans;
    }
};