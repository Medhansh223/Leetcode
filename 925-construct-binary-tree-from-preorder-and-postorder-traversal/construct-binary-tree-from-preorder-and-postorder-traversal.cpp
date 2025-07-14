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
    TreeNode* buildtree(vector<int>&preorder,int prestart,int preend,vector<int>&postorder,int poststart,int postend,map<int,int>mpp)
    {
        if(prestart>preend || poststart>postend)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[prestart]);
        if(prestart==preend)
        {
            return root;
        }
        TreeNode* leftroot=new TreeNode(preorder[prestart+1]);
        int leftrootind=mpp[leftroot->val];
        int numleft=leftrootind-poststart+1;
        root->left=buildtree(preorder,prestart+1,prestart+numleft,postorder,poststart,leftrootind,mpp);
        root->right=buildtree(preorder,prestart+numleft+1,preend,postorder,leftrootind+1,postend-1,mpp);
        return root;
    }   
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int,int>mpp;
        for(int i=0;i<postorder.size();i++)
        {
            mpp[postorder[i]]=i;
        }
        return buildtree(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1,mpp);
    }
};