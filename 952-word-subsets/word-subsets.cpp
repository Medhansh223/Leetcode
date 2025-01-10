class Solution {
public:
    map<char,int>countalphabet(string& str)
    {
        map<char,int>ans;
        for(auto c:str)
        {
            ans[c]++;
        }
        return ans;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int>words2max;
        for(auto it:words2)
        {
            map<char,int>words2count=countalphabet(it);
            for(auto pair:words2count)
            {
                char c=pair.first;
                words2max[c]=max(words2max[c],words2count[c]);
            }
        }
        vector<string>ans;
        for(auto it:words1)
        {
            map<char,int>words1count=countalphabet(it);
            bool subset=true;
            for(auto pair:words2max)
            {
                char c=pair.first;
                if(words1count[c]<words2max[c])
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