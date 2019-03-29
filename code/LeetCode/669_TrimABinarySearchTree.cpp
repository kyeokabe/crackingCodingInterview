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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        
        if (root==nullptr)
            return nullptr;
        
        vector<int> foo;
        getInt(root, foo, L, R);
        
        TreeNode* head=nullptr;
        
        for(int i=0; i<foo.size();i++){
            TreeNode *ptr;
            ptr = new TreeNode(foo[i]);
            if (head==nullptr)
                head=ptr;
            else
            {
                insertNode(head,ptr);
            }
        }
        return head;
    }
    
    void getInt(TreeNode* root, vector<int> &foo, int L, int R){
        if (root==nullptr)
            return;
        cout<<root->val<<endl;
        if (root->val<=R && root->val>=L){
            foo.push_back(root->val);
        }
        if (root->right!=nullptr)
            getInt(root->right, foo, L, R);
        if(root->left!=nullptr)
            getInt(root->left, foo, L, R);
        return;
    }
    
    void insertNode(TreeNode* root, TreeNode* ptr){
        if (root->val > ptr->val){
            if (root->left==nullptr)
                root->left=ptr;
            else
                insertNode(root->left,ptr);
        }
        
        if (root->val < ptr->val){
            if (root->right==nullptr)
                root->right=ptr;
            else
                insertNode(root->right,ptr);
        }            
    }
};
