class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mpp;
        int s=tasks.size();
        priority_queue<int>pq;
        for(int i=0;i<s;i++)
        {
            mpp[tasks[i]]++;
        }
        for(auto &it:mpp)
        {
            int c=it.first;
            int f=it.second;
            pq.push(f);
        }
        int time=0;
        while(!pq.empty())
        {
            vector<int>temp;
            for(int i=1;i<=n+1;i++)
            {
                if(!pq.empty())
                {
                    int freq=pq.top();
                    freq--;
                    pq.pop();
                    temp.push_back(freq);
                }
            }
            for(int &f:temp)
            {
                if(f>0)
                {
                    pq.push(f);
                }
            }
            if(pq.empty())
            {
                time=time+temp.size();
            }
            else
            {
                time=time+(n+1);
            }
        }
        return time;
    }
};