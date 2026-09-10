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
    pair<int,int>dfs(TreeNode* root, int& result)
    {
        if(root == NULL)
        {
            return {0,0};
        }
        auto [ls,lc] = dfs(root->left, result);
        auto [rs,rc] = dfs(root->right, result);
        int sum = ls + rs + root->val;
        int count = lc + rc + 1;
        if(sum/count == root->val)
        {
            result++;
        }
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
};