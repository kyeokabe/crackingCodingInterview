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
    int minDepth(TreeNode* root) {
        if (root==nullptr)
            return 0;
        int depth=1;
        depth=helper(depth, root);
        return depth;
    }
    
    int helper(int depth, TreeNode* root){
        if (root->right==nullptr&&root->left==nullptr)
            return depth;

        if (root->right==nullptr&&root->left!=nullptr)
            return helper(depth+1,root->left);
        if (root->left==nullptr&&root->right!=nullptr)
            return helper(depth+1,root->right);
        
        //if both child nodes not nullptr
        int tempR=helper(depth+1,root->right);
        int tempL=helper(depth+1,root->left);
        
        return min(tempR,tempL);
    }
};
