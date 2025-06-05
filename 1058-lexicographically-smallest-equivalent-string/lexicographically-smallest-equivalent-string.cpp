class Solution {
public:
    char dfs(char sh, vector<int>& visited, map<char,vector<char>>& adj)
    {
        visited[sh-'a']=1;
        char minchar=sh;
        for(auto it:adj[sh])
        {
            if(visited[it-'a']==0)
            {
                minchar=min(minchar,dfs(it,visited,adj));
            }
        }
        return minchar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        map<char,vector<char>>adj;
        for(int i=0;i<n;i++)
        {
            char u=s1[i];
            char v=s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string result;
        int m=baseStr.size();
        for(int i=0;i<m;i++)
        {
            char sh=baseStr[i];
            vector<int>visited(26,0);
            char mini=dfs(sh,visited,adj);
            result.push_back(mini);
        }
        return result;
    }
};