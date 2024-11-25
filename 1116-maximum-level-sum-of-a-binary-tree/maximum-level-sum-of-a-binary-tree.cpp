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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        vector<int>res;
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        int maxi=INT_MIN;
        int leveli=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>level;
            count++;
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            int sum=0;
            for(int i=0;i<level.size();i++)
            {
                sum=sum+level[i];
            }
            if(sum>maxi)
            {
                maxi=sum;
                leveli=count;
            }
        }
        return leveli;
    }
};