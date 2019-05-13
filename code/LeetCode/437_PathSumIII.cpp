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
    int pathSum(TreeNode* ptr, int sum) {
        if (ptr==nullptr)
            return 0;
        //non help part passes the sum without adding current node
        return help(ptr, sum)+pathSum(ptr->right, sum)+pathSum(ptr->left, sum);
    }
    
    //help adds current node and passes the sum
    //need separate function to separate passes from no passes
    //i.e. count->pass w/o count->count situation
    int help(TreeNode* ptr, int sum){
        if (ptr==nullptr)
            return 0;
        return (sum-ptr->val==0)+help(ptr->right, sum-ptr->val)+help(ptr->left, sum-ptr->val);
    }
};
