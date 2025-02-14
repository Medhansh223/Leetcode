class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long total = 0;
        int n = costs.size();
        priority_queue<int,vector<int>,greater<int>>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2;
        int j = 0;
        while(j < candidates && j < n)
        {
            pq1.push(costs[j]);
            j++;
        }
        int i = n-1;
        while(candidates > 0 && i>=j)
        {
            pq2.push(costs[i]);
            i--;
            candidates--;
        }
        while(k > 0)
        {
            if(!pq1.empty() && (pq2.empty() || pq1.top() <= pq2.top()))
            {
                long long num = pq1.top();
                total = total + num;
                pq1.pop();
                if(j <= i)
                {
                    pq1.push(costs[j]);
                    j++;
                }
            }
            else
            {
                long long num = pq2.top();
                total = total + num;
                pq2.pop();
                if(i >= j)
                {
                    pq2.push(costs[i]);
                    i--;
                }
            }
            k--;
        }
        return total;
    }
};