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
    void traversal(TreeNode* root, vector<int>& inorder)
    {
        if(root==NULL)
        {
            return;
        }
        traversal(root->left,inorder);
        inorder.push_back(root->val);
        traversal(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        if(root==NULL)
        {
            return false;
        }
        traversal(root,inorder);
        int n=inorder.size();
        int left=0;
        int right=n-1;
        while(left<right)
        {
            int sum=inorder[left]+inorder[right];
            if(sum==k)
            {
                return true;
            }
            else if(sum>k)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return false;
    }
};