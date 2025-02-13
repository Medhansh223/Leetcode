class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n = nums.size();
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        while(!pq.empty())
        {
            int num = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            if(vis[index]==true)
            {
                continue;
            }
            vis[index]=true;
            if((index - 1) >= 0)
            {
                vis[index - 1]=true;
            }
            if((index + 1) <= (n-1))
            {
                vis[index + 1]=true;
            }
            score = score + (long long)nums[index];
        }
        return score;
    }
};