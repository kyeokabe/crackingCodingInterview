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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL && q==NULL)
            return true;
        if ((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
            return false;
        bool isSameVal=(p->val==q->val);
        bool LeftSameTree=isSameTree(p->left,q->left);
        bool RightSameTree=isSameTree(p->right,q->right);
        
        return isSameVal&&LeftSameTree&&RightSameTree;
    }
};
