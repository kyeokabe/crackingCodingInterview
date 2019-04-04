/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==nullptr)
            return false;
        int total=0;
        return helper(root, sum, total);
    }
    
    bool helper(TreeNode* root, int sum, int total){
        if (root==nullptr)
            return false;
        total+=root->val;
        if (sum==total&&root->right==nullptr&&root->left==nullptr)
            return true;
        return helper(root->right,sum,total)||helper(root->left,sum,total);
    }
    
};
