/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark(TreeNode* root, map<TreeNode*, TreeNode*>& parent, TreeNode* target)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left)
            {
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*>parent;
        mark(root,parent,target);
        map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int distance=0;
        while(!q.empty())
        {
            if(distance==k)
            {
                break;
            }
            else
            {
                distance++;
            }
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !visited[curr->left])
                {
                    visited[curr->left]=true;
                    q.push(curr->left);
                }
                if(curr->right && !visited[curr->right])
                {
                    visited[curr->right]=true;
                    q.push(curr->right);
                }
                if(parent[curr] && !visited[parent[curr]])
                {
                    visited[parent[curr]]=true;
                    q.push(parent[curr]);
                }
            }
        }
        vector<int>result;
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            result.push_back(node->val);
        }
        return result;
    }
};