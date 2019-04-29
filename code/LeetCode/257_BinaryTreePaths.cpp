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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root==nullptr)
            return ans;
        string s=to_string(root->val);
        helper(root,ans,s);
        return ans;
    }
    
    void helper(TreeNode* ptr, vector<string> &ans, string s){
        if(ptr->left==nullptr&&ptr->right==nullptr)
            ans.push_back(s);
        
        if (ptr->left!=nullptr)
            helper(ptr->left,ans,s+"->"+to_string(ptr->left->val));
        
        if (ptr->right!=nullptr)
            helper(ptr->right,ans,s+"->"+to_string(ptr->right->val));
    }
};
