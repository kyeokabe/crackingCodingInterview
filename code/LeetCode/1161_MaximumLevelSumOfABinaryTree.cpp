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
    int maxLevelSum(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int level=1;
        int current=1;
        getLevel(root,level,current);
        vector<int> v(level+1,0);
        sumLevel(root,current,v);
        int ans_sum=INT_MIN;
        int ans_ind=0;
        for(int i=1;i<v.size();i++)
            if(v[i]>ans_sum){
                ans_sum=v[i];
                ans_ind=i;
            }
        return ans_ind;
    }
    
    void getLevel(TreeNode* root, int &level,int current){
        if(root==nullptr)
            return;
        if(current>level)
            level=current;
        getLevel(root->left,level,current+1);
        getLevel(root->right,level,current+1);
    }
    
    void sumLevel(TreeNode* root, int current, vector<int> &v){
        if(root==nullptr)
            return;
        v[current]+=root->val;
        sumLevel(root->left,current+1,v);
        sumLevel(root->right,current+1,v);
    }
    
};
