class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(stones[i]);
        }
        while(pq.size()>1)
        {
            int s1=pq.top();
            pq.pop();
            int s2=pq.top();
            pq.pop();
            if(s1==s2)
            {
                continue;
            }
            else
            {
                s1=s1-s2;
                pq.push(s1);
            }
        }
        if(pq.size()==0)
        {
            return 0;
        }
        return pq.top();
    }
};