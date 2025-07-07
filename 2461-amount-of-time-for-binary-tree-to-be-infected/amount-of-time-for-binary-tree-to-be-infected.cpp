/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mark(map<TreeNode*,TreeNode*>& parent, TreeNode* root, int target)
    {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* result;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->val == target)
            {
                result = node;
            }
            if(node->left)
            {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return result;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>parent;
        TreeNode* result = mark(parent,root,start);
        map<TreeNode*,bool>visited;
        visited[result] = true;
        queue<TreeNode*>q;
        q.push(result);
        int time = 0;
        while(!q.empty())
        {
            int flag = 0;
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    flag = 1;
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right])
                {
                    flag = 1;
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parent[node] && !visited[parent[node]])
                {
                    flag = 1;
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
            if(flag == 1)
            {
                time++;
            }
        }
        return time;
    }
};