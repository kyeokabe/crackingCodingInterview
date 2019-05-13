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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        return help(root);
    }
    
    int help(TreeNode *ptr){
        int countL=1;
        int countR=1;
        int L=0;
        int R=0;
        if(ptr->left!=nullptr){
            L=getlen(ptr->left,countL);
        }
        if(ptr->right!=nullptr)
            R=getlen(ptr->right,countR);
        int len1=L+R;
        int len2=0;
        if(ptr->left!=nullptr)
            len2=help(ptr->left);
        int len3=0;
        if(ptr->right!=nullptr)
            len3=help(ptr->right);
        return (max(len1,max(len2,len3)));
    }
    
    int getlen(TreeNode *ptr, int count){
        if(ptr!=nullptr)
            //cout<<"ptr->val = "<<ptr->val<<endl;
        if(ptr->left==nullptr&&ptr->right==nullptr){
            //cout<<"count = "<<count<<endl;
            return count;
        }
        else if(ptr->left!=nullptr&&ptr->right==nullptr)
            return (getlen(ptr->left,count+1));
        
        else if(ptr->left==nullptr&&ptr->right!=nullptr)
            return (getlen(ptr->right,count+1));
        
            return max(getlen(ptr->left,count+1),getlen(ptr->right,count+1));
    }
};
