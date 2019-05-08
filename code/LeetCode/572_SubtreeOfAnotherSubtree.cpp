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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==nullptr&&t==nullptr)//if both trees are nullptrs, return true
            return true;
        else if(s==nullptr&&t!=nullptr)//if only 1 tree is a nullptr return false
            return false;
        else if(t==nullptr&&s!=nullptr)//if only 1 tree is a nullptr return false
            return false;
        
        if(s->val==t->val&&isExact(s->left,t->left)&&isExact(s->right,t->right))
            return true;
        
        return isSubtree(s->left,t)||isSubtree(s->right,t);
    }
        
    bool isExact(TreeNode* s, TreeNode* t){
        if(!s&&!t)//if both trees are nullptrs, return true
            return true;
        else if(s==nullptr&&t!=nullptr)//if only 1 tree is a nullptr return false
            return false;
        else if(t==nullptr&&s!=nullptr)//if only 1 tree is a nullptr return false
            return false;
        else if(s->val!=t->val){ //if top values don't match, check next subtree of s
            return false;
        }
        return isExact(s->left,t->left)&&isExact(s->right,t->right);
    }
};
