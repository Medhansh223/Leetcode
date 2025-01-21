class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long uppersum=accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long lowersum=0;
        long long minsum=LLONG_MAX;
        int n=grid[0].size();
        for(int i=0;i<n;i++)
        {
            uppersum=uppersum-grid[0][i];
            minsum=min(minsum, max(uppersum, lowersum));
            lowersum=lowersum+grid[1][i];
        }
        return minsum;
    }
};