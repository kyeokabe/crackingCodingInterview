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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        unordered_map<TreeNode*,int> m;
        unordered_map<TreeNode*,TreeNode*> m2;
        help(root,m);
        getParent(root,m2);
        
        if(root->val==x){
            if(root->right!=nullptr)
                if(2*m[root->right]>n)
                    return true;
            if(root->left!=nullptr)
                if(2*m[root->left]>n)
                    return true;
            return false;
        }
        auto it=m2.begin();
        TreeNode* ptr=nullptr;
        while(it!=m2.end()){
            if(it->first->val==x){
                ptr=it->first;
                break;
            }
            it++;
        }
        
        if(ptr->left!=nullptr)
            if(2*m[ptr->left]>n)
                return true;
        if(ptr->right!=nullptr)
            if(2*m[ptr->right]>n)
                return true;
        if(2*(n-m[ptr])>n)
            return true;
        return false;
    }
    
    void getParent(TreeNode* ptr, unordered_map<TreeNode*,TreeNode*> &m2){
        if(ptr->right!=nullptr){
            m2[ptr->right]=ptr;
            getParent(ptr->right,m2);
        }
        if(ptr->left!=nullptr){
            m2[ptr->left]=ptr;
            getParent(ptr->left,m2);
        }
    }
    
    void help(TreeNode* ptr, unordered_map<TreeNode*,int> &m){
        if(ptr->left!=nullptr)
            help(ptr->left,m);
        if(ptr->right!=nullptr)
            help(ptr->right,m);
        int L=0;
        int R=0;
        if(ptr->left!=nullptr)
            L=m[ptr->left];
        if(ptr->right!=nullptr)
            R=m[ptr->right];
        m[ptr]=1+L+R;
    } 
};
