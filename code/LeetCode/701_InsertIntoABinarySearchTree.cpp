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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root==nullptr){
            root = new TreeNode(val);
            return root;
        }
        helper(root, val);
        return root;
    }
    
    void helper(TreeNode* root, int val){
        if(root->val>val){
            if(root->left==nullptr){
                TreeNode *ptr;
                ptr = new TreeNode(val);
                root->left=ptr;
                return;
            }
            else
                (helper(root->left,val));
        }
        
        if(root->val<val){
            if(root->right==nullptr){
                TreeNode *ptr;
                ptr = new TreeNode(val);
                root->right=ptr;
                return;
            }
            else
                (helper(root->right,val));
        }
        
    }
    
};
