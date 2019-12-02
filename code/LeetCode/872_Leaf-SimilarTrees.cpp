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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        
        help(root1,v1);
        help(root2,v2);
        
        if(v1.size()!=v2.size())
            return false;
        for(int i=0;i<v1.size();i++)
            if(v1[i]!=v2[i])
                return false;
        return true;
    }
    
    void help(TreeNode* &ptr, vector<int> &v){
        if(ptr==nullptr)
            return;
        if(ptr->left!=nullptr)
            help(ptr->left,v);
        if(ptr->right!=nullptr)
            help(ptr->right,v);
        if(ptr->left==nullptr&&ptr->right==nullptr)
            v.push_back(ptr->val);
    }
};
