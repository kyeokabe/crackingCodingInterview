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
    int maxDepth(TreeNode* root) {
        int foo=0;
        int depth=0;
        depthCheck(root,foo,depth);
        return foo;
    }
    
    void depthCheck(TreeNode* root, int &foo, int depth){
        if (root==nullptr)
            return;
        depth++;
        if (depth>foo)
            foo++;
        depthCheck(root->right,foo,depth);
        depthCheck(root->left,foo,depth);
    }
    
};
