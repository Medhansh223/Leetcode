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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>result;
        if(root == NULL)
        {
            return result;
        }
        map<int,map<int,multiset<int>>>mpp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            root = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            mpp[x][y].insert(root->val);
            if(root->left != NULL)
            {
                q.push({root->left,{x-1,y+1}});
            }
            if(root->right != NULL)
            {
                q.push({root->right,{x+1,y+1}});
            }
        }
        for(auto it:mpp)
        {
            vector<int>temp;
            for(auto s:it.second)
            {
                temp.insert(temp.end(),s.second.begin(),s.second.end());
            }
            result.push_back(temp);
        }
        return result;
    }
};