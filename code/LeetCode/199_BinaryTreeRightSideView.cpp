/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
Ot(n) where n is number of nodes
Om(l) where l is number of levels
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> foo={};
        if (root==nullptr)
            return foo;
        //getdepth
        int count=0;
        int depth=0;
        getdepth(root,count,depth);
        
        //checked[i] checks if depth i+1
        //has been looked at or not
        vector<bool> checked;
        for (int i=0;i<depth;i++){
            checked.push_back(false);
        }
        
        punchInNumbs(root, checked, foo, count);
        
        return foo;
    }
    
    void getdepth(TreeNode* root, int count, int &depth){
        if (root==nullptr)
            return;
        count++;
        if (depth<count)
            depth=count;
        if (root->left!=nullptr)
            getdepth(root->left,count,depth);
        if (root->right!=nullptr)
            getdepth(root->right,count,depth);
    }
    
    void punchInNumbs(TreeNode* root, vector<bool> &checked, vector<int> &foo, int count){
        if (root==nullptr)
            return;
        if (checked[count]==false){
            foo.push_back(root->val);
            checked[count]=true;
        }
        count++;
        if (root->right!=nullptr)
            punchInNumbs(root->right,checked,foo,count); 
        if (root->left!=nullptr)
            punchInNumbs(root->left,checked,foo,count);
    }

};
