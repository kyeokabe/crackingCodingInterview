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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size()==0)
            return nullptr;
        TreeNode* ptr = new TreeNode(preorder[0]);
        if (preorder.size()==1)
            return ptr;
        for (int i=1;i<preorder.size();i++){
            TreeNode* temp = new TreeNode(preorder[i]);
            helper(ptr,temp);
        }
        return ptr;
    }
    
    void helper(TreeNode* &ptr, TreeNode* &temp){
        if (temp->val>ptr->val&&ptr->right!=nullptr)
            helper(ptr->right,temp);
        if (temp->val>ptr->val&&ptr->right==nullptr){
            ptr->right=temp;
            return;
        }
        
        if (temp->val<ptr->val&&ptr->left!=nullptr)
            helper(ptr->left,temp);
        if (temp->val<ptr->val&&ptr->left==nullptr){
            ptr->left=temp;
            return;
        }          
    }
};
