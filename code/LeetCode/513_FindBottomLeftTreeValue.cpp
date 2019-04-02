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
    int findBottomLeftValue(TreeNode* root) {
        int count=0;
        int depth=0;
        //find depth of tree
        getDepth(root, depth, count);        
        //in order traversal, if val matches, return number
        int ans=0;
        helper(root, depth, count, ans);
        return ans;
    }
    
    void getDepth(TreeNode* root, int &depth, int count){
        if (root==nullptr)
            return;
        count++;
        if (depth<count)
            depth=count;
        if (root->left!=nullptr)
            getDepth(root->left, depth, count);
        if (root->right!=nullptr)
           getDepth(root->right,depth, count);
    }
    
    void helper(TreeNode* root, int depthOfTree, int count, int &ans){
        if (root==nullptr)
            return;
        count++;
        if (root->right!=nullptr)
            helper(root->right,depthOfTree,count,ans);
        
        if (count==depthOfTree)
            ans=root->val;
        
        if (root->left!=nullptr)
            helper(root->left,depthOfTree,count,ans);
    }
    
    //good example of incorrect code attempting recurrsion 
    /*
    int helper(TreeNode* root, int depthOfTree, int count){
                
        count++;
        cout<<"depth = "<<depthOfTree<<endl;
        cout<<"count = "<<count<<endl;
        if (count==depthOfTree){
            cout<<"return"<<endl;
            return root->val;
        }
        if (root->left!=nullptr)
            helper(root->left,depthOfTree,count);
        if (root->right!=nullptr)
            helper(root->right,depthOfTree,count);
        return root->val;
    
    }*/
    
};
