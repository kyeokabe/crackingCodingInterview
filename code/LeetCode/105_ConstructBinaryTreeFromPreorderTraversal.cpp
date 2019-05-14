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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0)
            return nullptr;
        vector<int> Lpre;
        vector<int> Lin;
        vector<int> Rpre;
        vector<int> Rin;
        int i=0;
        while(inorder[i]!=preorder[0]){
            Lin.push_back(inorder[i]);
            ++i;
        }
        for(int j=i+1;j<inorder.size();j++)
            Rin.push_back(inorder[j]);
        for(int j=1;j<=i;j++)
            Lpre.push_back(preorder[j]);
        for(int j=i+1;j<preorder.size();j++)
            Rpre.push_back(preorder[j]);

        TreeNode* ptr = new TreeNode(preorder[0]);
        helpL(ptr, Lpre,Lin);
        helpR(ptr, Rpre,Rin);
        
        return ptr;
    }
    
    //
    void helpL(TreeNode* ptr, vector<int> preorder, vector<int> inorder){
        if (preorder.size()==0)
            return;

        vector<int> Lpre;
        vector<int> Lin;
        vector<int> Rpre;
        vector<int> Rin;
        int i=0;
        while(inorder[i]!=preorder[0]){
            Lin.push_back(inorder[i]);
            ++i;
        }
        for(int j=i+1;j<inorder.size();j++)
            Rin.push_back(inorder[j]);
        for(int j=1;j<=i;j++)
            Lpre.push_back(preorder[j]);
        for(int j=i+1;j<preorder.size();j++)
            Rpre.push_back(preorder[j]);
        
        TreeNode* ptr2 = new TreeNode(preorder[0]);
        ptr->left=ptr2;
        helpL(ptr2, Lpre,Lin);
        helpR(ptr2, Rpre,Rin);
    }

    void helpR(TreeNode* ptr, vector<int> preorder, vector<int> inorder){
        if (preorder.size()==0)
            return;
        vector<int> Lpre;
        vector<int> Lin;
        vector<int> Rpre;
        vector<int> Rin;
        int i=0;
        while(inorder[i]!=preorder[0]){
            Lin.push_back(inorder[i]);
            ++i;
        }
        for(int j=i+1;j<inorder.size();j++)
            Rin.push_back(inorder[j]);
        for(int j=1;j<=i;j++)
            Lpre.push_back(preorder[j]);
        for(int j=i+1;j<preorder.size();j++)
            Rpre.push_back(preorder[j]);
        
        TreeNode* ptr2 = new TreeNode(preorder[0]);
        ptr->right=ptr2;
        helpL(ptr2, Lpre,Lin);
        helpR(ptr2, Rpre,Rin);
    }
    
};
