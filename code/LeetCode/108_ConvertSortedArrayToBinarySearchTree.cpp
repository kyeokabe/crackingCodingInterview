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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return nullptr;
        TreeNode* ptr = new TreeNode(nums[nums.size()/2]);
        if(nums.size()==1)
            return ptr;
        
        vector<int> left;
        for(int i=0;i<nums.size()/2;i++)
            left.push_back(nums[i]);
        
        vector<int> right;
        for(int i=nums.size()/2+1;i<nums.size();i++)
            right.push_back(nums[i]);
        
        help(ptr,left,right);
        return ptr;
    }
    
    void help(TreeNode* ptr, vector<int> left, vector<int> right){
        if(left.size()==0 && right.size()==0)
            return;
        
        if(left.size()!=0){
            TreeNode* ptrL = new TreeNode(left[left.size()/2]);
            ptr->left=ptrL;
            
            vector<int> leftleft,leftright;
            for(int i=0;i<left.size()/2;i++)
                leftleft.push_back(left[i]);  
            for(int i=left.size()/2+1;i<left.size();i++)
                leftright.push_back(left[i]);
            help(ptr->left,leftleft,leftright);
        }

        if(right.size()!=0){
            TreeNode* ptrR = new TreeNode(right[right.size()/2]);
            ptr->right=ptrR;
            
            vector<int> rightright,rightleft;
            for(int i=0;i<right.size()/2;i++)
                rightleft.push_back(right[i]);  
            for(int i=right.size()/2+1;i<right.size();i++)
                rightright.push_back(right[i]);
            help(ptr->right,rightleft,rightright);
        }
    }
    
};
