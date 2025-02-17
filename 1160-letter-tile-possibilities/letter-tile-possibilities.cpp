class Solution {
public:
    void solve(vector<int>& vec, int& count)
    {
        count++;
        for(int i=0;i<26;i++)
        {
            if(vec[i] == 0)
            {
                continue;
            }
            vec[i]--;
            solve(vec, count);
            vec[i]++;
        }
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        int count = 0;
        vector<int>vec(26,0);
        for(char ch : tiles)
        {
            vec[ch - 'A']++;
        }
        solve(vec, count);
        return count - 1;
    }
};