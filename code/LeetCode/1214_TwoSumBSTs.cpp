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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(root1==nullptr||root2==nullptr)
            return false;
        unordered_map<int,int> m;
        //help function stores all Tree1 vals in HashMap
        help(root1,m);
        return help2(root2,m,target);
    }
    
    void help(TreeNode* root1, unordered_map<int,int> &m){
        if(root1==nullptr)
            return;
        m[root1->val]++;
        help(root1->left,m);
        help(root1->right,m);
    }
    
    bool help2(TreeNode* root2, unordered_map<int,int> &m, int target){
        auto it=m.find(target-root2->val);
        if(it!=m.end())
            return true;
        bool left=false;
        bool right=false;
        if(root2->left!=nullptr)
            left=help2(root2->left,m,target);
        if(root2->right!=nullptr)
            right=help2(root2->right,m,target);
        return (left||right);
    }
    
};
