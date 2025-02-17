class Solution {
public:
    void solve(string tiles, vector<bool>& used, set<string>& st, string& curr, int n)
    {
        st.insert(curr);
        for(int i=0;i<n;i++)
        {
            if(used[i] == true)
            {
                continue;
            }
            used[i] = true;
            curr.push_back(tiles[i]);
            solve(tiles, used, st, curr, n);
            used[i] = false;
            curr.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool>used(n,false);
        set<string>st;
        string curr = "";
        solve(tiles, used, st, curr, n);
        return st.size() - 1;
    }
};