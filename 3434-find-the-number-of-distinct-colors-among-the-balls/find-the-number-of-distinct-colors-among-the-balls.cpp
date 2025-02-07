class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        map<int,int>color_freq;
        map<int,int>ball_color;
        vector<int>result(n);
        for(int i=0;i<n;i++)
        {
            int ball = queries[i][0];
            int color = queries[i][1];
            if(ball_color.count(ball))
            {
                color_freq[ball_color[ball]]--;
                if(color_freq[ball_color[ball]]==0)
                {
                    color_freq.erase(ball_color[ball]);
                }
            }
            ball_color[ball] = color;
            color_freq[color]++;
            result[i] = color_freq.size();
        }
        return result;
    }
};