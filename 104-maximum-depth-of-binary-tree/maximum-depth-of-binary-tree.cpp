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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        while(!q.empty())
        {
            vector<int>level;
            int n=q.size();
            count++;
            for(int i=0;i<n;i++)
            {
                root=q.front();
                q.pop();
                level.push_back(root->val);
                if(root->left!=NULL)
                {
                    q.push(root->left);
                }
                if(root->right!=NULL)
                {
                    q.push(root->right);
                }
            }
        }
        return count;
    }
};