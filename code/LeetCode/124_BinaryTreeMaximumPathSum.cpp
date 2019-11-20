//adapted from jeantimex
//https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/39875/Elegant-Java-solution

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
    int maxPathSum(TreeNode* root) {    
        int ans=INT_MIN;
        help(root,ans);
        return ans;
    }
    
    int help(TreeNode* root,int& ans){
        if(root==nullptr)
            return 0;
        int L=help(root->left,ans);
        int R=help(root->right,ans);
        int temp=root->val+max(0,L)+max(0,R);
        if(temp>ans)
            ans=temp;
        int temp2=root->val+max(0,L);
        int temp3=root->val+max(0,R);
        int temp4=root->val;
        int temp5=max(0,max(temp4,max(temp3,temp2)));
        return temp5;
    }
};
