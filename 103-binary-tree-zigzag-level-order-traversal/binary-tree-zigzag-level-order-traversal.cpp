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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL)
        {
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        while(!q.empty())
        {
            int s=q.size();
            vector<int>temp;
            for(int i=0;i<s;i++)
            {
                root=q.front();
                q.pop();
                temp.push_back(root->val);
                if(root->left)
                {
                    q.push(root->left);
                }
                if(root->right)
                {
                    q.push(root->right);
                }
            }
            if(!flag)
            {
                reverse(temp.begin(),temp.end());
            }
            flag=!flag;
            result.push_back(temp);
        }
        return result;
    }
};