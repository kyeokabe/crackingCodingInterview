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
    int maxAncestorDiff(TreeNode* root) {
        if (root==nullptr)
            return 0;
        int min=root->val;
        int max=root->val;
        int ans = 0;
        helper(root,min,max,ans);
        return ans;
    }
    
    void helper(TreeNode* root, int min, int max, int &ans){
        if (root==nullptr)
            return;
        if (root->val>max)
            max=root->val;
        if (root->val<min)
            min=root->val;
        if (abs(max-min)>ans)
            ans=abs(max-min);
        helper(root->right,min,max,ans);
        helper(root->left,min,max,ans);
    }
    
};
