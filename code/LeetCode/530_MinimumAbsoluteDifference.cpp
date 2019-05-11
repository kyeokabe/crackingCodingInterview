/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//O(n) time solution, O(n) memory solution
//traversing in order prevents need for sort which is O(nlog(n))
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        help(root,v);
        //sort(v.begin(),v.end());
        int ans=v[1]-v[0];
        for(int i=0;i<v.size()-1;i++)
            if (v[i+1]-v[i]<ans)
                ans=v[i+1]-v[i];
        return ans;
    }
    
    void help(TreeNode* root, vector<int> &v){
        if (root==nullptr)
            return;
        help(root->left,v);
        v.push_back(root->val);
        help(root->right,v);
    }
};
