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
    int countNodes(TreeNode* root) {
        if (root==nullptr)
            return 0;
        int ans=0;
        help(root,ans);
        return ans;
    }
    
    void help(TreeNode* ptr, int &ans){
        if (ptr==nullptr)
            return;
        ans++;
        help(ptr->right,ans);
        help(ptr->left,ans);
    }
    
};
