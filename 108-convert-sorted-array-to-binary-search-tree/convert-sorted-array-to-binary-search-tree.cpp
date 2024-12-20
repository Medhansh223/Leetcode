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
    TreeNode* sortArray(vector<int>& nums, int start, int end)
    {
        if(start>=end)
        {
            return NULL;
        }
        int middle=(end+start)/2;
        TreeNode* root=new TreeNode(nums[middle]);
        root->left=sortArray(nums,start,middle);
        root->right=sortArray(nums,middle+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        {
            return NULL;
        }
        return sortArray(nums,0,n);
    }
};