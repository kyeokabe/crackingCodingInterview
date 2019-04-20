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
    void flatten(TreeNode* root) {
        queue <TreeNode*> s;
        helper(root,s);
        if (root==nullptr)
            return;
        if (root->left!=nullptr)
            root->left=nullptr;
        s.pop();
        TreeNode* ptr=root;
        while(!s.empty()){
            ptr->left=nullptr;
            ptr->right=s.front();
            ptr=ptr->right;
            s.pop();
        }
        ptr->left=nullptr;
        ptr->right=nullptr;
    }
    
    void helper(TreeNode* root, queue <TreeNode*> &s){
        if (root==nullptr)
            return;
        s.push(root);
        helper(root->left, s);
        helper(root->right, s);
    }
};
