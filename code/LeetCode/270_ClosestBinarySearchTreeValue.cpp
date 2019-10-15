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
    int closestValue(TreeNode* root, double target) {
        double temp=abs(root->val-target);
        int ans=root->val;
        help(root,target,temp,ans);
        return ans;
    }
    
    void help(TreeNode* root, double &target, double &temp, int &ans){
        if (abs(root->val-target)<temp){
            temp=abs(root->val-target);
            ans=root->val;
        }
        if(root->left!=nullptr)
            help(root->left,target,temp,ans);
        if(root->right!=nullptr)
            help(root->right,target,temp,ans);
    }
    
};
