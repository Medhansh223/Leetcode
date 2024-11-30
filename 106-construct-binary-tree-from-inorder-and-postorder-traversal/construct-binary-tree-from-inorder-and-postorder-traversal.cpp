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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
    }
    TreeNode* build(vector<int>& postorder, int poststart, int postend, vector<int>& inorder, int instart, int inend, map<int,int>& mpp)
    {
        if(poststart>postend || instart>inend)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[postend]);
        int inroot=mpp[root->val];
        int numleft=inroot-instart;
        root->left=build(postorder,poststart,poststart+numleft-1,inorder,instart,inroot-1,mpp);
        root->right=build(postorder,poststart+numleft,postend-1,inorder,inroot+1,inend,mpp);
        return root;
    }
};