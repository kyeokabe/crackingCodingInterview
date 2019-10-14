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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        vector<int> v;
        for(int i=0;i<=n;i++)
            v.push_back(i);
        
        for(int i=1;i<=n;i++){
            TreeNode* ptr=new TreeNode(i);
            v[i]=0;
            int count=1;
            help(ptr,v,count,ans);
            v[i]=i;
        }
        return ans;
    }
    
    void help(TreeNode* ptr, vector<int> &v, int count, vector<TreeNode*> &ans){
        if(count==v.size()-1){
            ans.push_back(ptr);
            return;
        }
        
        for(int i=1;i<=v.size()-1;i++){
            if(v[i]!=0){
                TreeNode* ptr2=ptr;
                while(ptr2!=nullptr){
                    if(ptr2->val>v[i]){
                        if(ptr2->left==nullptr)
                            break;
                        else
                            ptr2=ptr2->left;
                    }
                    else{
                        if(ptr2->right==nullptr)
                            break;
                        else
                            ptr2=ptr2->right;
                    }
                }
                TreeNode* ptr3=new TreeNode(v[i]);
                if(v[i]>ptr2->val)
                    ptr2->right=ptr3;
                else
                    ptr2->left=ptr3;
                v[i]=0;
                help(ptr,v,count+1,ans);
                v[i]=i;
            }
        } 
    }
    
};
