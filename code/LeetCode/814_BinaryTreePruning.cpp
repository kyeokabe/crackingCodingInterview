class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root==nullptr)
            return nullptr;
        help(root);
        return root;
    }
    void help(TreeNode* ptr){
        if (has1(ptr->left))
            help(ptr->left);//note this causes memory leak
        else
            ptr->left=nullptr;
        if (has1(ptr->right))
            help(ptr->right);
        else
            ptr->right=nullptr;
    }
    
    bool has1(TreeNode* ptr){
        if (ptr==nullptr)
            return false;
        if (ptr->val==1)
            return true;
        return has1(ptr->left)||has1(ptr->right);
    }
};
