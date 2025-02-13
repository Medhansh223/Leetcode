class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto it: piles)
        {
            pq.push(it);
        }
        while(k>0 && !pq.empty())
        {
            int num = pq.top();
            pq.pop();
            num = num - (num/2);
            pq.push(num);
            k--;
        }
        int sum = 0;
        while(!pq.empty())
        {
            int num = pq.top();
            pq.pop();
            sum = sum + num;
        }
        return sum;
    }
};