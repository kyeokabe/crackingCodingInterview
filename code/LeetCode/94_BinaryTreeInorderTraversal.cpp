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
core algorithm is "copy and paste," 
but need a wraper function due to vector return
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> foo;
        if (root==nullptr)
            return foo;
        inorderTraversal(root,foo);
        return foo;
    }
    
    void inorderTraversal(TreeNode* root, vector<int> &foo){
        if (root==nullptr)
            return;
        inorderTraversal(root->left,foo);
        foo.push_back(root->val);
        inorderTraversal(root->right,foo);
    }
};
