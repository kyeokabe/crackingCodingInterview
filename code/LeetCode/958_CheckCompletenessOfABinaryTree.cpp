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
    bool isCompleteTree(TreeNode* r) {
        if(r==nullptr)
            return true;
        int count=0;
        int depth=0;
        getdepth(r,count,depth);
        bool check=false;
        bool ans=true;
        help(r,depth,count,check,ans);
        return ans;
    }
    
    
    void help(TreeNode* r, int depth,int count, bool &check,bool &ans){
        
        if(r->left!=nullptr)
            help(r->left,depth,count+1,check,ans);   
        
        if((r->left==nullptr||r->right==nullptr)&&count+1<depth){
            ans=false;
            return;
        }
        
        if(count!=depth)
            if(r->left==nullptr||r->right==nullptr)
                check=true;
        //cout<<"r->val"<<r->val<<" depth = "<<depth<<" count = "<<count<<" check = "<<check<<endl;

        if(check&&count==depth){
            ans=false;
            return;
        }
    
        if(r->right!=nullptr)
            help(r->right,depth,count+1,check,ans);
        
        return;
    }
    
    void getdepth(TreeNode* r, int count, int &depth){
        
        if(count>depth)
            depth=count;
        if(r->left!=nullptr)
            getdepth(r->left,count+1,depth);
        if(r->right!=nullptr)
            getdepth(r->right,count+1,depth);
    }
    
};
