class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mpp;
        for(auto it:s)
        {
            mpp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mpp)
        {
            pq.push({it.second,it.first});
        }
        string result="";
        while(!pq.empty())
        {
            char ch = pq.top().second;
            int count = pq.top().first;
            pq.pop();
            result.append(count,ch);
        }
        return result;
    }
};