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
    bool isUnivalTree(TreeNode* root) {
        if(root==nullptr)
            return true;
        int k = root->val;
        return help(root,k);
    }
    
    bool help(TreeNode* ptr, int k){
        if (ptr==nullptr)
            return true;
        if(ptr->val!=k)
            return false;
        return help(ptr->left,k)&&help(ptr->right,k);
    }
    
};
