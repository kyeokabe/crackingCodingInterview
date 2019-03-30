/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        fillQ(root);
    }
    
    void fillQ(TreeNode* root){
        if (root==nullptr)
            return;
        if (root->left!=nullptr)
            fillQ(root->left);
        foo.push(root->val);
        if (root->right!=nullptr)
            fillQ(root->right);
        return;
    }
    
    /** @return the next smallest number */
    int next() {
        int g=foo.front();
        foo.pop();
        return g;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !foo.empty();
    }

private:    
    queue<int> foo;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
