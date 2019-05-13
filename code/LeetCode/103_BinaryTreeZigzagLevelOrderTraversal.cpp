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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==nullptr)
            return v;
        int count=0;
        int depth=0;
        getdepth(root,count,depth);
        for(int i=0;i<depth;i++){
            vector<int> temp={};
            v.push_back(temp);
        }
        help(root,v,count);
        
        for(int i=0;i<depth;i++){
            if(i%2==1){
                vector<int> temp=v[i];
                vector<int> temp2;
                for(int j=0;j<temp.size();j++)
                    temp2.push_back(temp[temp.size()-1-j]);
                v[i]=temp2;
            }
        }
        
        return v;
    }
    
    void help(TreeNode* ptr, vector<vector<int>> &v,int count){
        if (ptr==nullptr)
            return;
        vector<int> temp= v[count];
        temp.push_back(ptr->val);
        v[count]=temp;
        help(ptr->left,v,count+1);
        help(ptr->right,v,count+1);
    }
    
    void getdepth(TreeNode* ptr, int count, int &depth){
        if (ptr==nullptr)
            return;
        ++count;
        if(depth<count)
            depth=count;
        getdepth(ptr->right,count,depth);
        getdepth(ptr->left,count,depth);
    }
    
};
