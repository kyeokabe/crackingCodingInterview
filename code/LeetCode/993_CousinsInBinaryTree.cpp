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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==nullptr)
            return false;
        
        if(root->val==x||root->val==y)
            return false;
        
        int depth_x=0;
        int depth_y=0;
        
        TreeNode* xp=nullptr;
        TreeNode* yp=nullptr;
        
        int count=0;
        
        get(root,count, depth_x,xp,x);
        get(root,count, depth_y,yp,y);
                
        if(depth_x==depth_y&&yp!=xp)
            return true;
        else
            return false;
    }
    
    void get(TreeNode* root, int count, int &depth, TreeNode* &p,int target){
        if(root==nullptr)
            return;
        if(root->left!=nullptr&&root->left->val==target){
            p=root;
            depth=count;
            return;
        }
        if(root->right!=nullptr&&root->right->val==target){
            p=root;
            depth=count;
            return;
        }
        
        get(root->left,count+1,depth,p,target);
        get(root->right,count+1,depth,p,target);
    }
    
};
