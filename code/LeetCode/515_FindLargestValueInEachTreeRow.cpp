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
    vector<int> largestValues(TreeNode* root) {
        if (root==nullptr)
            return {};
        int depth=-1;
        int count=-1;
        getdepth(root,depth,count);
        vector<int> ans;
        for(int i=0;i<=depth;i++)
            ans.push_back(-pow(2,31));
        help(root,count,ans);
        return ans;
    }
    
    void getdepth(TreeNode* root, int &depth, int count){
        if (root==nullptr)
            return;
        count++;
        if(count>depth)
            depth=count;
        getdepth(root->right, depth, count);
        getdepth(root->left,depth,count);
    }
    
    void help(TreeNode* root, int count, vector<int> &ans){
        if (root==nullptr)
            return;
        count++;
        if(root->val>ans[count])
            ans[count]=root->val;
        help(root->left, count, ans);
        help(root->right, count, ans);
    }
    
};
