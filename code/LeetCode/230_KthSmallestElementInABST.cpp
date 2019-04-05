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
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int answer;
        helper(root,k,count,answer);
        return answer;
    }
    
    void helper(TreeNode* root, int k, int &count, int &answer){
        if(root->left!=nullptr)
           helper(root->left,k,count,answer);
        count++;
        if (k==count){
            answer=root->val;
            return;
        }
        if (root->right!=nullptr)
            helper(root->right,k,count,answer);
    }
    
};
