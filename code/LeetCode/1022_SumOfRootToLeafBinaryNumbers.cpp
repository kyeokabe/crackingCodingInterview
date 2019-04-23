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
    int sumRootToLeaf(TreeNode* root) {
         if (root==nullptr)
             return 0;
        vector<stack<int>> foo;
        stack<int> foo2;
        helper(root,foo,foo2);
        int ans=0;
        for (int i=0;i<foo.size();i++){
            ans+=helper2(foo[i]);
            //cout<<helper2(foo[i])<<endl;
        }
        return ans;
    }
    
    //converts ptr into vector of stacks
    void helper(TreeNode* ptr, vector<stack<int>> &foo, stack<int> foo2){
        foo2.push(ptr->val);
        if (ptr->right==nullptr&&ptr->left==nullptr){
            foo.push_back(foo2);
            return;
        }
        if (ptr->left!=nullptr)
            helper(ptr->left, foo, foo2);
        if (ptr->right!=nullptr)
            helper(ptr->right, foo, foo2);
    }
    
    //converts stack of binary number into nums 
    int  helper2(stack<int> s){
        int ans=0;
        int count=0;
        int SIZE=s.size();
        for (int i=0;i<SIZE;i++){
            //cout<<"s top = "<<s.top()<<endl;
            ans+=s.top()*pow(2,count);
            count++;
            s.pop();
        }
        return ans;
    }
    
};
