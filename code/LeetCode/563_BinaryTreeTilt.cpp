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
    int findTilt(TreeNode* root) {
        if(root==0)
            return 0;
        int ans=0;
        help(root,ans);
        return ans;
    }
    
    void help(TreeNode* root, int &ans){
        if(root->left!=nullptr)
            help(root->left,ans);
        if(root->right!=nullptr)
            help(root->right,ans);
        int L=0;
        int R=0;
        if(root->left!=nullptr)
            L=root->left->val;
        if(root->right!=nullptr)
            R=root->right->val;
        
        ans+=abs(L-R);
        root->val+=(L+R);
    }
    
};
