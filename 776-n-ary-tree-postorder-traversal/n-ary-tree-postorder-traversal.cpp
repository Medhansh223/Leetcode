/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>post(Node* root, vector<int>&ans)
    {
        if(root==NULL)
        {
            return ans;
        }
        for(auto it:root->children)
        {
            post(it,ans);
        }
        ans.push_back(root->val);
        return ans;
    }
    vector<int> postorder(Node* root) {
        vector<int>ans;
        if(root==NULL)
        {
            return ans;
        }
        post(root,ans);
        return ans;
    }
};