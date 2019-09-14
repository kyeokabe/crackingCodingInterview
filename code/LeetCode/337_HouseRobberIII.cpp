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
        
        if(root->right==nullptr&&root->left==nullptr)
            return root->val;
        if(root->right==nullptr&&root->left!=nullptr)
            return max(root->val+rob2(root->left,true),rob2(root->left,false));
        if(root->right!=nullptr&&root->left==nullptr)
            return max(root->val+rob2(root->right,true),rob2(root->right,false));
        
        int a = root->val+rob2(root->right,true)+rob2(root->left,true);
        int b = rob2(root->right,false)+rob2(root->left,false);
        return max(a,b);
        }
    
    int rob2(TreeNode* root, bool skipMe){
        if(root==nullptr)
            return 0;
        
        if(!skipMe){
            int a=rob2(root->left,false)+rob2(root->right,false);
            int b=root->val+rob2(root->left,true)+rob2(root->right,true);
            return max(a,b);
        }
        else
            return rob2(root->left,false)+rob2(root->right,false);
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
