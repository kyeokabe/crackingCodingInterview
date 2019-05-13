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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> v;
        vector<int> v2={};
        if (root==nullptr)
            return v;
        
        help(root,sum,v2,v);
        return v;
    }
    
    void help(TreeNode* root, int sum,vector<int> temp, vector<vector<int>> &v){
        if(sum-root->val==0&&root->left==nullptr&&root->right==nullptr){
            temp.push_back(root->val);
            v.push_back(temp);
        }
        else if(sum-root->val!=0&&root->left==nullptr&&root->right==nullptr)
            return;
        temp.push_back(root->val);
        if(root->left!=nullptr)
            help(root->left,sum-root->val,temp,v);
        if(root->right!=nullptr)
            help(root->right,sum-root->val,temp,v);
    }
};
