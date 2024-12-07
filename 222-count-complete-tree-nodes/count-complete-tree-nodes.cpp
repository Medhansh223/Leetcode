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
    void countNode(TreeNode* root, int &count)
    {
        if(root==NULL)
        {
            return;
        }
        count++;
        countNode(root->left,count);
        countNode(root->right,count);
    }
    int countNodes(TreeNode* root) {
        int count=0;
        if(root==NULL)
        {
            return 0;
        }
        countNode(root,count);
        return count;
    }
};