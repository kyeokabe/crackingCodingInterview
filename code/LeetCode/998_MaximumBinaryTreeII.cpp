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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* ptr=new TreeNode(val);
        
        if(root==nullptr){
            return ptr;
        }
        else{
            if(root->val<val){
                TreeNode* ptr=new TreeNode(val);
                ptr->left=root;
                return ptr;
            }
            else{
                TreeNode* temp=root;
                while(temp->right!=nullptr&&temp->right->val>val)
                    temp=temp->right;
                TreeNode* temp2=temp->right;
                temp->right=ptr;
                ptr->left=temp2;
                return root;
            }
        }
        //return root;
    }
};
