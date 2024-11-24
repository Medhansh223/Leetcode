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
    bool isBST(TreeNode* root, long long int lower, long long int higher)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->val<=lower || root->val>=higher)
        {
            return false;
        }
        return (isBST(root->left, lower, root->val) && isBST(root->right, root->val, higher));
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        long long int lower=LONG_MIN;
        long long int higher=LONG_MAX;
        return isBST(root,lower,higher);
    }
};