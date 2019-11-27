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
    double maximumAverageSubtree(TreeNode* root) {
        unordered_map<TreeNode*, int> num_subTree;
        unordered_map<TreeNode*, int> sum;
        unordered_map<TreeNode*, double> average;
        
        help(root,num_subTree,sum,average);
        auto it=average.begin();
        double ans=0;
        while(it!=average.end()){
            if(it->second>ans)
                ans=it->second;
            it++;
        }
        return ans;
    }
    
    void help(TreeNode* ptr,unordered_map<TreeNode*,int> &num_subTree,unordered_map<TreeNode*, int> &sum, unordered_map<TreeNode*, double> &average){
        if(ptr->left!=nullptr)
            help(ptr->left,num_subTree,sum,average);
        if(ptr->right!=nullptr)
            help(ptr->right,num_subTree,sum,average);
        if(ptr->left!=nullptr)
            ptr->val+=ptr->left->val;
        if(ptr->right!=nullptr)
            ptr->val+=ptr->right->val;
        sum[ptr]=ptr->val;
        num_subTree[ptr]= 1+((ptr->left==nullptr)?0:num_subTree[ptr->left])+((ptr->right==nullptr)?0:num_subTree[ptr->right]);
        average[ptr]=double(sum[ptr])/double(num_subTree[ptr]);
    }
};
