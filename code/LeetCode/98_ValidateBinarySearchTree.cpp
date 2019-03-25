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
        long max_allowed=pow(2,42)-1;
        long min_allowed=-pow(2,42);
        return isValidBST(root, max_allowed, min_allowed);
    }
    
    bool isValidBST(TreeNode* root, long max_allowed, long min_allowed){
        if (root==nullptr)
            return true;
        if (root->val >= max_allowed)
            return false;
        if (root->val <= min_allowed)
            return false;
        
        bool checkRight=true;
        bool checkLeft=true;
        
        if (root->right!=nullptr){
            if (root->val > min_allowed){
                //cout<<"foo1"<<endl;
                checkRight=isValidBST(root->right, max_allowed,root->val);
            }
            else
                checkRight=isValidBST(root->right,max_allowed,min_allowed);
        }
        
        if (root->left!=nullptr){
            if (root->val < max_allowed)
                checkLeft=isValidBST(root->left, root->val,min_allowed);
            else
                checkLeft=isValidBST(root->left,max_allowed,min_allowed);
        }        
        return (checkRight && checkLeft);
    }
};
