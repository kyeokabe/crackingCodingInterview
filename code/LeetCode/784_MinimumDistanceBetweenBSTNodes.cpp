/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
Ot(NlogN) ... limited by merge sort
Om(N) ...     limited by merge sort as well as vector creation
*/
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        if (root==nullptr)
            return 0;
        vector<int> foo={};
        helper(root,foo);
        sort(foo.begin(),foo.end());
        int min=pow(2,31)-1;
        for (int i=0;i<foo.size()-1;i++){
            if (abs(foo[i+1]-foo[i])<min)
                min=abs(foo[i+1]-foo[i]);
        }
        return min;
    }
    
    void helper(TreeNode* root, vector<int> &foo){
        if (root==nullptr)
            return;
        if (root->left!=nullptr)
            helper(root->left,foo);
        foo.push_back(root->val);
        if (root->right!=nullptr)
            helper(root->right,foo);
    }
    
};
