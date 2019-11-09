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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        TreeNode* temp=root;
        if(root==nullptr)
            return ans;
        
        ans.push_back(root->val);
        
        if(temp->left!=nullptr){
            while(temp->right!=nullptr||temp->left!=nullptr){
                if(temp->left!=nullptr){
                   if(temp->left->left!=nullptr||temp->left->right!=nullptr)
                        ans.push_back(temp->left->val);
                    temp=temp->left;
                }
                else if (temp->right!=nullptr){
                    if(temp->right->left!=nullptr||temp->right->right!=nullptr)
                        ans.push_back(temp->right->val);
                    temp=temp->right;
                }
            }
        }
        
        temp=root;
        if(!(root->left==nullptr&&root->right==nullptr))
            help(temp,ans);
        
        temp=root;
        vector<int> foo;
        if(temp->right!=nullptr){
            while(temp->right!=nullptr||temp->left!=nullptr){
                if(temp->right!=nullptr){
                   if(temp->right->left!=nullptr||temp->right->right!=nullptr)
                        foo.push_back(temp->right->val);
                    temp=temp->right;
                }
                else if (temp->left!=nullptr){
                    if(temp->left->left!=nullptr||temp->left->right!=nullptr)
                        foo.push_back(temp->left->val);
                    temp=temp->left;
                }
            }
        }
    
        for(int i=foo.size()-1;i>=0;i--)
            ans.push_back(foo[i]);
        return ans;
    }
    
    void help(TreeNode* temp, vector<int> &ans){
        if(temp->left==nullptr&&temp->right==nullptr)
            ans.push_back(temp->val);
        if(temp->left!=nullptr)
            help(temp->left,ans);
        if(temp->right!=nullptr)
            help(temp->right,ans);
    }
};
