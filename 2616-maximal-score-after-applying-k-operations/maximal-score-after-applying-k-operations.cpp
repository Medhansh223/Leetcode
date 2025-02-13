class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long>pq;
        for(auto it:nums)
        {
            pq.push((long long)it);
        }
        long long sum = 0;
        while(k>0 && !pq.empty())
        {
            long long num = pq.top();
            pq.pop();
            sum = sum + num;
            pq.push(ceil(num/3.0));
            k--;
        }
        return sum;
    }
};