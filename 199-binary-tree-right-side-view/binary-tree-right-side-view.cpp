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
    void traversal(vector<int>&result, int level, TreeNode* root)
    {
        if(root == NULL)
        {
            return ;
        }
        if(result.size() < level)
        {
            result.push_back(root->val);
        }
        traversal(result,level+1,root->right);
        traversal(result,level+1,root->left);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root == NULL)
        {
            return result;
        }
        traversal(result,1,root);
        return result;
    }
};