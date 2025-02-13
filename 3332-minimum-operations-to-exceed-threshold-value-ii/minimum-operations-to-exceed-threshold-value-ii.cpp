class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push((long long)nums[i]);
            // if(nums[i]<k)
            // {
            //     pq.push((long long)nums[i]);
            // }
        }
        int op=0;
        while(pq.size()>1 && pq.top()<k)
        {
            long long first=pq.top();
            pq.pop();
            // if(pq.empty())
            // {
            //     break;
            // }
            long long second=pq.top();
            pq.pop();
            long long num=first*2+second;
            pq.push(num);
            op++;
        }
        return op;
    }
};