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
    int countUnivalSubtrees(TreeNode* root) {
        if(root==nullptr)
            return 0;
        unordered_map<TreeNode*,int> m;
        int count=0;
        help(root,m,count);
        return count;
    }

    
    void help(TreeNode* ptr,unordered_map<TreeNode*,int> &m,int &count){
        if(ptr->left!=nullptr)
            help(ptr->left,m,count);
        if(ptr->right!=nullptr)
            help(ptr->right,m,count);
        if(ptr->left==nullptr&&ptr->right==nullptr){
            m[ptr]++;
            count++;
        }
        else if(ptr->left==nullptr&&ptr->right!=nullptr){
            if(m[ptr->right]==1&&ptr->right->val==ptr->val){
                m[ptr]++;
                count++;
            }
            else
                m[ptr]=2;
        }
        else if(ptr->right==nullptr&&ptr->left!=nullptr){
            if(m[ptr->left]==1&&ptr->left->val==ptr->val){
                m[ptr]++;
                count++;
            }
            else
                m[ptr]=2;
        }
        else{
            if(m[ptr->left]==1&&ptr->left->val==ptr->val&&m[ptr->right]==1&&ptr->right->val==ptr->val){
                m[ptr]++;
                count++;
            }
            else
                m[ptr]=2;
        }
        
    }
    
};
