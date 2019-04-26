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
    int sumNumbers(TreeNode* root) {
        if (root==nullptr)
            return 0;
        vector<stack<int>> foo;
        stack<int> temp;
        helper(foo,temp,root);
        int ans=0;
        for (int i=0;i<foo.size();i++){
            ans+=helper2(foo[i]);
        }
        
        return ans; 
    }
    
    void helper(vector<stack<int>> &foo, stack<int> temp, TreeNode* root){
        temp.push(root->val);
        if (root->left!=nullptr)
            helper(foo,temp,root->left);
        if (root->right!=nullptr)
            helper(foo,temp,root->right);
        if (root->left==nullptr&&root->right==nullptr)
            foo.push_back(temp);
        return;
    }
    
    int helper2(stack<int> s){
        int ans=0;
        int count=0;
        while(!s.empty()){
            ans+=(s.top()%10)*pow(10,count);
            count++;
            s.pop();
        }
        return ans;
    }  
};
