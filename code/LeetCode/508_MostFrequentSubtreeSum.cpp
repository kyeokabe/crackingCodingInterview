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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        //https://leetcode.com/problems/most-frequent-subtree-sum/discuss/98751/C%2B%2B-unordered_map-solution
        //adapted from lzl124631x
        vector<int> ans={};
        int maxC=0;
        if (!root)
            return ans;
        unordered_map<int,int> m;
        help(root,m,maxC);
        
        for(auto it=m.begin();it!=m.end();it++){
            if (it->second==maxC)
                ans.push_back(it->first);
        }
        return ans;
    }
    
    int help(TreeNode* ptr, unordered_map<int,int> &m, int &maxC){
        if(!ptr)
            return 0;
        int sum=ptr->val+help(ptr->left,m,maxC)+help(ptr->right,m,maxC);
        m[sum]++;//apparently maps values are initialized with 0;
        if(maxC<m[sum])
            maxC=m[sum];
        return sum;
    }
    
};
