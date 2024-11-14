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
    void rightside(TreeNode* root, int level, vector<int>& result)
    {
        if(root==NULL)
        {
            return;
        }
        if(result.size()==level)
        {
            result.push_back(root->val);
        }
        rightside(root->right, level+1, result);
        rightside(root->left, level+1, result);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root==NULL)
        {
            return result;
        }
        rightside(root,0,result);
        return result;
    }
};