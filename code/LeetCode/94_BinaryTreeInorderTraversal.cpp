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


/*

//iterative solution added 10/10/2019
//O(n) time
//O(n) memory
//adapted from lvlolitte
//https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31213/Iterative-solution-in-Java-simple-and-readable

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        
        while(root!=nullptr||!s.empty()){
            while(root!=nullptr){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            v.push_back(root->val);
            root=root->right;
        }
        
        return v;
    }
};

*/
