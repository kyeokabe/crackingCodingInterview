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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
    
    void helper(TreeNode* root, int &ans){
        if (root==nullptr)
            return;
        if (root->left!=nullptr){
            if (root->left->left==nullptr && root->left->right==nullptr)
                ans+=root->left->val;
            else
                helper(root->left,ans);
        }
        if (root->right!=nullptr)
            helper(root->right,ans);
    }  
};
