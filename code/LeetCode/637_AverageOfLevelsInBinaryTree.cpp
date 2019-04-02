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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root==nullptr)
            return {};
        stack<TreeNode*> Tstack;
        vector<double> ans={};
        Tstack.push(root);
        helper(Tstack,ans);
        return ans;
    }
    
    //<functionality of helper>
    //check all elements in Tstack
    //if for all elements in Tstack, get sum of vals
    //if Tstack nodes have children, push to nextStack
    //get average of vals and push to ans
    //call helper again using nextStack
    void helper(stack<TreeNode*> Tstack, vector<double> &ans){
        
        if (Tstack.empty()==true)
            return;
        double temp=0;
        double count=0;
        stack<TreeNode*> nextStack;
        while(Tstack.empty()==false){
            if (Tstack.top()==nullptr)
                Tstack.pop();
            else{
                temp=(temp+Tstack.top()->val);
                count=count+1;
                if(Tstack.top()->left!=nullptr)
                    nextStack.push(Tstack.top()->left);
                if(Tstack.top()->right!=nullptr)
                    nextStack.push(Tstack.top()->right);
                Tstack.pop();
            }
        }
        temp=temp/count;
        ans.push_back(temp);
        helper(nextStack,ans);
    }  
};
