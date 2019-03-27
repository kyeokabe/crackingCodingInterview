/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 Used discussion's answer to get it right.
 */
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr)
            return true;
        return helper(root->right, root->left);
    }
    
    bool helper(TreeNode *right, TreeNode *left){
        if (right==nullptr && left==nullptr)
            return true;
        if (right==nullptr || left==nullptr)
            return false;
        return ((right->val==left->val) && helper(right->right,left->left) && helper(right->left, left->right));
    }
    
};
