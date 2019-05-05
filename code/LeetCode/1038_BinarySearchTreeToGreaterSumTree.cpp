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
    TreeNode* bstToGst(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        vector<int> foo;
        help(root,foo);
        for(int i=foo.size()-2;i>=0;i--){
            foo[i]+=foo[i+1];
        }
        int i=0;
        help2(root,foo,i);
        return root;
    }
    
    void help(TreeNode* root, vector<int> &foo){
        if(root==nullptr)
            return;
        help(root->left,foo);
        foo.push_back(root->val);
        help(root->right,foo);
    }
    
    void help2(TreeNode* root, vector<int> &foo, int &i){
        if(root->left!=nullptr)
            help2(root->left,foo,i);
        root->val=foo[i];
        i=i+1;
        if(root->right!=nullptr)
            help2(root->right,foo,i);
    }
};
