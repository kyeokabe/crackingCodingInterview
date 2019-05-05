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
    string smallestFromLeaf(TreeNode* root) {
        if(root==nullptr)
            return "";
        
        string temp="";
        vector<string> foo;
        help(root,foo, temp);
        sort(foo.begin(),foo.end());
        return foo[0];
    }
    
    void help(TreeNode* root, vector<string> &foo, string temp){
        temp=num2ch(root->val)+temp;
        if(root->left==nullptr&&root->right==nullptr){
            foo.push_back(temp);
            return;
        }
        if (root->left!=nullptr)
            help(root->left,foo,temp);
        if (root->right!=nullptr)
            help(root->right,foo,temp);
    }
    
    char num2ch(int n){
        if(n==0)
            return 'a';
        return ('a'+n);
    }
};
