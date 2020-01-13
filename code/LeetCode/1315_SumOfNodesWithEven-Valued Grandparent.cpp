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
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        help(ans,root);
        return ans;
    }
    
    void help(int &ans,TreeNode* ptr){
        if(ptr!=nullptr&&ptr->val%2==0&&ptr->left!=nullptr){
            if(ptr->left->left!=nullptr)
                ans+=ptr->left->left->val;
            if(ptr->left->right!=nullptr)
                ans+=ptr->left->right->val;
        }
        if(ptr!=nullptr&&ptr->val%2==0&&ptr->right!=nullptr){
            if(ptr->right->left!=nullptr)
                ans+=ptr->right->left->val;
            if(ptr->right->right!=nullptr)
                ans+=ptr->right->right->val;
        }
        if(ptr!=nullptr&&ptr->left!=nullptr)
            help(ans,ptr->left);
        if(ptr!=nullptr&&ptr->right!=nullptr)
            help(ans,ptr->right);
    }
};
