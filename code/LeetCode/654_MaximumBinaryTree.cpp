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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size()==0)
            return nullptr;
        TreeNode* ptr=new TreeNode(maxVAL(nums));
        helper(ptr,nums);
        return ptr;
    }
    
    void helper(TreeNode* &ptr, vector<int>& nums){
        if (nums.size()==0)
            return;
        vector<int> vR=getRight(nums,maxVAL(nums));
        vector<int> vL=getLeft(nums,maxVAL(nums));

        if(vR.size()!=0){
            TreeNode* temp=new TreeNode(maxVAL(vR));
            ptr->right=temp;
            helper(ptr->right,vR);
        }
        
        if(vL.size()!=0){
            TreeNode* temp=new TreeNode(maxVAL(vL));
            ptr->left=temp;
            helper(ptr->left,vL);
        }   
    }
    
    int maxVAL(vector<int> &v){
        if (v.size()==0)
            return 0;
        int foo=v[0];
        for (int i=0;i<v.size();i++)
            if (v[i]>foo)
                foo=v[i];
        return foo;
    }
    
    int maxINDEX(vector<int> &v, int k){
        if (v.size()==0)
            return 0;
        for (int i=0;i<v.size();i++)
            if (v[i]==k)
                return k;
        return 0;
    }
    
    vector<int> getRight(vector<int> v, int k){
        vector<int> v_R;
        int count=0;
        for(int i=0;i<v.size();i++){
            count++;
            if(v[i]==k)
                break;
        }
        if(count>=v.size())
            return v_R;
        for (int j=count;j<v.size();j++)
            v_R.push_back(v[j]);
        return v_R;
    }
    
    vector<int> getLeft(vector<int> v, int k){
        vector<int> v_L;
        for(int i=0;i<v.size();i++){
            if(v[i]==k)
                return v_L;
            else
                v_L.push_back(v[i]);
        }
        return v_L;
    }
    
};
