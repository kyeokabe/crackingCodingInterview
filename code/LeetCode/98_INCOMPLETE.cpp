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
    bool isValidBST(TreeNode* root) {
        if (root==nullptr)
            return true;
        int max=pow(2,32)-1;
        int min=-pow(2,32);
        return isValidBST(root, max, min);
    }
    
    bool isValidBST(TreeNode* root, int max, int min){
        if (root==nullptr)
            return true;
        if (root->val > max)
            return false;
        if (root->val < min)
            return false;
        
        bool checkRight=true;
        bool checkLeft=true;
        
        if (root->right!=nullptr){
            if (root->val < min)
                checkRight=isValidBST(root->right, max,root->val);
            else
                checkRight=isValidBST(root->right,max,min);
        }
        
        if (root->left!=nullptr){
            if (root->val > max)
                checkLeft=isValidBST(root->left, root->val,min);
            else
                checkLeft=isValidBST(root->left,max,min);
        }        
        
        return (checkRight && checkLeft);
        
    }
    
};
