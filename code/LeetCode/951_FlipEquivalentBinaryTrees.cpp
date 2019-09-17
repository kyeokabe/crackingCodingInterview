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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr&&root2==nullptr)
            return true;
        if(root1==nullptr&&root2!=nullptr)
            return false;
        if(root2==nullptr&&root1!=nullptr)
            return false;
        if(root1->val==root2->val){
            bool case1=flipEquiv(root1->right,root2->right)&&flipEquiv(root1->left,root2->left);
            bool case2=flipEquiv(root1->left,root2->right)&&flipEquiv(root1->right,root2->left);
            return case1||case2;
        }
        else
            return false;
    }
};
