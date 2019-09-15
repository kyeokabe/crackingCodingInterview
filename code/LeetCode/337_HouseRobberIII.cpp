// still need to do iterative solutions
/*

********************************
**Step 2. Recursive (top-down)**
********************************

class Solution {
public:
    int rob(TreeNode* root) {
        if(root==nullptr)
            return 0;
        
        int option1=root->val;
        if(root->right!=nullptr){
            option1+=rob(root->right->right);
            option1+=rob(root->right->left);
        }
        if(root->left!=nullptr){
            option1+=rob(root->left->left);
            option1+=rob(root->left->right);
        }
        
        int option2=rob(root->right)+rob(root->left);
    
        
        return max(option1,option2);
    }
};

*******************************************************
**Step 3. Recursive (Memoization ... i.e., top-down).**
*******************************************************

class Solution {
public:
    int rob(TreeNode* root) {
        if(root==nullptr)
            return 0;
        
        TreeNode* ptr = new TreeNode(INT_MIN);
        makeTree(root,ptr);
        
        return rob3(root,ptr);
    }
    
    void makeTree(TreeNode* root, TreeNode* ptr){
        if(root->left!=nullptr){
            TreeNode* ptr_left = new TreeNode(INT_MIN);
            ptr->left=ptr_left;
            makeTree(root->left,ptr_left);
        }
        if(root->right!=nullptr){
            TreeNode* ptr_right = new TreeNode(INT_MIN);
            ptr->right=ptr_right;
            makeTree(root->right,ptr_right);
        }
    }
    
    int rob3(TreeNode* root, TreeNode* ptr){
        if(root==nullptr)
            return 0;
        if(ptr->val!=INT_MIN)
            return ptr->val;
        else{
            int a=root->val;
            if(root->right!=nullptr){
                a+=rob3(root->right->right,ptr->right->right);
                a+=rob3(root->right->left,ptr->right->left);
            }
            if(root->left!=nullptr){
                a+=rob3(root->left->right,ptr->left->right);
                a+=rob3(root->left->left,ptr->left->left);
            }
            int b=rob3(root->right,ptr->right)+rob3(root->left,ptr->left);
            ptr->val=max(a,b);
            return ptr->val;
        }
    }
};
*/
