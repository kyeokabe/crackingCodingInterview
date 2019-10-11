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
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr)
            return false;
        
        unordered_map<int,TreeNode*> m;
        help(m,root);
        bool ans=false;
        help2(m,root,ans,k);
        return ans;
    }
    
    void help(unordered_map<int,TreeNode*> &m, TreeNode* root){
        if(root!=nullptr){
            m[root->val]=root;
            help(m,root->left);
            help(m,root->right);
        }
    }
    
    void help2(unordered_map<int,TreeNode*> &m, TreeNode* root, bool &ans,int k){
        if(root!=nullptr){
            auto it=m.find(k-root->val);
            if(it!=m.end()&&root!=it->second)
                ans=true;
            help2(m,root->left,ans,k);
            help2(m,root->right,ans,k);
        }
    }
    
    
};
