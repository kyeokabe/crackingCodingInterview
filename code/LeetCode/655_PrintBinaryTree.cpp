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
    vector<vector<string>> printTree(TreeNode* root) {
        if(root==nullptr){
            vector<string> temp={"None"};
            vector<vector<string>> ans={temp};
            return ans;
        }
        int height=0;
        help(root,height,1);
        
        vector<int> p(height,0);
        p[0]=1;
        for(int i=1;i<p.size();i++)
            p[i]=2*p[i-1]+1;
        
        vector<string> foo(p[p.size()-1],"");
        vector<vector<string>> v(height,foo);
        
        help2(root,0,v[0].size()/2,v);
        return v;
        
    }
    
    void help(TreeNode* root,int &height, int count){
        if(root==nullptr)
            return;
        if(height<count)
            height=count;
        if(root->left!=nullptr)
            help(root->left,height,count+1);
        if(root->right!=nullptr)
            help(root->right,height,count+1);
    }
    
    void help2(TreeNode* root, int r,int c,vector<vector<string>> &v){
        if(root==nullptr)
            return;
        v[r][c]=to_string(root->val);
        int delta=pow(2,v.size()-2-r);
            
        if(root->left!=nullptr){
            help2(root->left,r+1,c-delta,v);
        }
        if(root->right!=nullptr){
            help2(root->right,r+1,c+delta,v);
        }
    }
    
};

/*

h1 1
h2 3
h3 7
h4 15


height 3 ... 2,1
height 4 ... 4,2,1
height 5 ... 8,4,2,1

*/
