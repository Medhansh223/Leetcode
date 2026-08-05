class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto it : invocations)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<bool>suspicious(n,false);
        queue<int>q;
        q.push(k);
        suspicious[k] = true;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(suspicious[it] == false)
                {
                    suspicious[it] = true;
                    q.push(it);
                }
            }
        }
        vector<int>result;
        bool cannot = false;
        for(int i=0;i<n;i++)
        {
            if(suspicious[i] == true && indegree[i] > 0)
            {
                cannot = true;
                break;
            }
            if(suspicious[i] == false)
            {
                result.push_back(i);
            }
        }   
        if(cannot == true)
        {
            vector<int>vec(n);
            for(int i=0;i<n;i++)
            {
                vec[i] = i;
            }
            return vec;
        }
        return result;
    }
};