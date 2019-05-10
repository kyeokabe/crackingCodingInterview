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
    vector<int> findMode(TreeNode* root) {
        if(root==nullptr)
            return {};
        unordered_map<int,int> m;
        help(m,root);
        vector<int> ans;
        int temp=0;
        for (auto it=m.begin();it!=m.end();it++){
            if(it->second>temp){
                temp=it->second;
                ans={};
                ans.push_back(it->first);
            }
            else if(it->second==temp){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
    
    void help(unordered_map<int,int> &m, TreeNode* root){
        if(root==nullptr)
            return;
        ++m[root->val];
        help(m,root->left);
        help(m,root->right);
    }
};
