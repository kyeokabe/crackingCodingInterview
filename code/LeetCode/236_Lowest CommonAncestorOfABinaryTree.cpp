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
idea:
from root, how to get to p and q? Using 2 queues Qp and Qq, push ptr from root to get to p/q
then, compare Qp and Qq. Pop front when they are the same and get last equal ptrs
if nothing common, root is LCA
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
            return nullptr;
        if(root->val==p->val||root->val==q->val)
            return root;
        if((exists(root->left,p)&&exists(root->right,q))||(exists(root->left,q)&&exists(root->right,p)))
            return root;
        if(exists(root->left,p)&&exists(root->left,q))
            return lowestCommonAncestor(root->left,p,q);

        return lowestCommonAncestor(root->right,p,q);
    }
    
    bool exists(TreeNode* root, TreeNode* p){
        if(root==nullptr)
            return false;
        if(root->val==p->val)
            return true;
        bool rightbool=false;
        bool leftbool=false;
        if(root->right!=nullptr)
            rightbool=exists(root->right,p);
        if(root->left!=nullptr)
            leftbool=exists(root->left,p);
        return (rightbool||leftbool);
    }
};
