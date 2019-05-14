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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)
            return nullptr;
        TreeNode* ptr = new TreeNode(postorder[postorder.size()-1]);
        vector<int> Lio,Rio,Lpo,Rpo;
        int i=0;
        while(inorder[i]!=postorder[postorder.size()-1]){
            Lio.push_back(inorder[i]);
            Lpo.push_back(postorder[i]);
            ++i;
        }
        for(int j=i;j<postorder.size()-1;j++){
            Rpo.push_back(postorder[j]);
            Rio.push_back(inorder[j+1]);
        }
        bool Left=true;        
        help(ptr,Lio,Lpo,Left);
        help(ptr,Rio,Rpo,false);
        return ptr;
    }
    
    void help(TreeNode* ptr, vector<int> inorder, vector<int> postorder, bool Left){
        if(inorder.size()==0)
            return;
        TreeNode* ptr2 = new TreeNode(postorder[postorder.size()-1]);
        vector<int> Lio,Rio,Lpo,Rpo;
        int i=0;
        while(inorder[i]!=postorder[postorder.size()-1]){
            Lio.push_back(inorder[i]);
            Lpo.push_back(postorder[i]);
            ++i;
        }
        for(int j=i;j<postorder.size()-1;j++){
            Rpo.push_back(postorder[j]);
            Rio.push_back(inorder[j+1]);
        }
        if(Left)
            ptr->left=ptr2;
        else
            ptr->right=ptr2;
        help(ptr2,Lio,Lpo,true);
        help(ptr2,Rio,Rpo,false);  
    }
    
};
