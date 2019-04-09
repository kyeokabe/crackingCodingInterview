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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root==nullptr)
            return {};
        int depth=0;
        int count=0;
        getdepth(root,depth,count);
        vector<vector<int>> foo;
        for (int i=0;i<depth;i++){
            vector<int> temp={};
            foo.push_back(temp);
        }
        helper(root,count, foo);
        return foo;
    }
    
    void getdepth(TreeNode* root, int &depth, int count){
        if (root==nullptr)
            return;
        count++;
        if (depth<count)
            depth=count;
        getdepth(root->left,depth,count);
        getdepth(root->right,depth,count);
    }
    
    void helper(TreeNode* root, int count, vector<vector<int>> &foo){
        if(root==nullptr)
            return;
        count++;
        vector<int> temp = foo[foo.size()-count];
        temp.push_back(root->val);
        foo[foo.size()-count]=temp;
        helper(root->left,count,foo);
        helper(root->right,count,foo);
    }
};
