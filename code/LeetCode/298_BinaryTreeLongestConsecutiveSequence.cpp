/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//O(n) time

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int ans=0;
        help(root,1,ans);//check increasing as going down
        //check decreasing as going down (not necessary)
        //help2(root,1,ans);
        return ans;
    }
    
    void help(TreeNode* root, int count, int &ans){
        if(count>ans)
            ans=count;
        if(root==nullptr)
            return;

        if(root->left!=nullptr){
            if(root->left->val-root->val==1)
                help(root->left,count+1,ans);
            else
                help(root->left,1,ans);
        }
        
        if(root->right!=nullptr){
            if(root->right->val-root->val==1)
                help(root->right,count+1,ans);
            else
                help(root->right,1,ans);
        }
    }
    
    void help2(TreeNode* root, int count, int &ans){
        if(count>ans)
            ans=count;
        if(root==nullptr)
            return;

        if(root->left!=nullptr){
            if(root->left->val-root->val==-1)
                help2(root->left,count+1,ans);
            else
                help2(root->left,1,ans);
        }
        
        if(root->right!=nullptr){
            if(root->right->val-root->val==-1)
                help2(root->right,count+1,ans);
            else
                help2(root->right,1,ans);
        }
    }   
};
