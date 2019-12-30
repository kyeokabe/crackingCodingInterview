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
    int deepestLeavesSum(TreeNode* root) {
        int ans=0;
        int max_depth=0;
        int count=0;
        help(root,ans,max_depth,count);
        return ans;
    }
    
    void help(TreeNode* ptr, int &ans, int &max_depth,int count){
        if(count==max_depth)
            ans+=ptr->val;
        if(count>max_depth){
            max_depth=count;
            ans=ptr->val;
        }
        if(ptr->left!=nullptr)
            help(ptr->left,ans,max_depth,count+1);
        if(ptr->right!=nullptr)
            help(ptr->right,ans,max_depth,count+1);
    }
    
};
