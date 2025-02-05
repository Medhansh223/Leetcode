class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        if(intervals.size()==0)
        {
            return ans;
        }
        sort(intervals.begin(),intervals.end(),comp);
        vector<int>temp=intervals[0];
        for(auto it:intervals)
        {
            int s = it[0];
            int e = it[1];
            if(s<=temp[1])
            {
                temp[1] = max(e,temp[1]);
            }
            else
            {
                ans.push_back(temp);
                temp=it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};