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
    TreeNode* increasingBST(TreeNode* root) {
        if (root==nullptr)
            return nullptr;
        queue<int> foo;
        help1(root,foo);
        TreeNode* ptr = new TreeNode(foo.front());
        TreeNode* head = ptr;
        foo.pop();
        while(!foo.empty()){
            TreeNode* ptr2 = new TreeNode(foo.front());
            ptr->right=ptr2;
            ptr=ptr->right;
            foo.pop();
        }
        return head;
    }
    
    void help1(TreeNode* ptr, queue<int> &foo){
        if(ptr->left!=nullptr)
            help1(ptr->left,foo);
        foo.push(ptr->val);
        if(ptr->right!=nullptr)
            help1(ptr->right,foo);
    }
    
};
