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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d==1){
            TreeNode* temp = new TreeNode(v);
            temp->left=root;
            return temp;
        }
        int count=1;
        help(root,v,d,count);
        return root;
    }
    
    void help(TreeNode* ptr, int v, int d, int count){
        if(count>=d)//makes program more efficient
            return;

        if(count+1==d){
                TreeNode* tempL = new TreeNode(v);
                tempL->left=ptr->left;
                ptr->left=tempL;
            
                TreeNode* tempR = new TreeNode(v);
                tempR->right=ptr->right;
                ptr->right=tempR;
        }
        if (ptr->left!=nullptr)
            help(ptr->left,v,d,count+1);
        if (ptr->right!=nullptr)
            help(ptr->right,v,d,count+1);
    }
};
