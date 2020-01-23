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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        unordered_map<TreeNode*,TreeNode*> m;
        m[root]=nullptr;
        help(root,m);
        while(root->left!=nullptr||root->right!=nullptr){
            vector<int> temp;
            help2(root,m,temp);
            ans.push_back(temp);
        }
        ans.push_back({root->val});
        return ans;
    }
    
    void help2(TreeNode* ptr, unordered_map<TreeNode*,TreeNode*> &m,vector<int> &temp){
        if(m[ptr]!=nullptr&&ptr->left==nullptr&&ptr->right==nullptr){
            temp.push_back(ptr->val);
            if(m[ptr]->left==ptr)
                m[ptr]->left=nullptr;
            else
                m[ptr]->right=nullptr;
        }
        if(ptr->left!=nullptr)
            help2(ptr->left,m,temp);
        if(ptr->right!=nullptr)
            help2(ptr->right,m,temp);
    }
    
    void help(TreeNode* ptr, unordered_map<TreeNode*,TreeNode*> &m){
        if(ptr->left!=nullptr){
            m[ptr->left]=ptr;
            help(ptr->left,m);
        }
        if(ptr->right!=nullptr){
            m[ptr->right]=ptr;
            help(ptr->right,m);
        }
    }
    
    
    
};
