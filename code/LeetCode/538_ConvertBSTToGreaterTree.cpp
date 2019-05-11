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
    TreeNode* convertBST(TreeNode* root) {
        vector<int> v;
        help(root,v);
        for(int i=v.size()-2;i>=0;i--){
            v[i]+=v[i+1];
        }
        int count=0;
        help2(v,root,count);
        return root;
    }
    
    void help(TreeNode* ptr, vector<int> &v){
        if(ptr==nullptr)
            return;
        help(ptr->left,v);
        v.push_back(ptr->val);
        help(ptr->right,v);
    }
    
    void help2(vector<int> v, TreeNode* ptr, int &count){
        if(ptr==nullptr)
            return;
        help2(v,ptr->left,count);
        ptr->val=v[count];
        ++count;
        help2(v,ptr->right,count);
    }
};
