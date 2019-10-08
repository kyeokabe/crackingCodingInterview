//time complexity: O(nlog(n))
//space complexity: O(n)
//basic idea is that in-order traversal for BST gives sorted order
//store array in memory and compare with "correct answer"
//can further optimize by doing an in-order and reverse in-order
//traversal and returning pointers when sort is incorrect
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
    void recoverTree(TreeNode* root) {
        if(root==nullptr)
            return;
        vector<int> v1;
        vector<int> v2;
        
        help(root,v1);
        v2=v1;
        sort(v2.begin(),v2.end());
        int ptr1=0;
        int ptr2=v2.size()-1;

        
        while(v1[ptr1]==v2[ptr1]){
            ptr1++;
        }
        while(v1[ptr2]==v2[ptr2]){
            ptr2--;
        }

        int target1=v1[ptr1];
        int target2=v1[ptr2];
        TreeNode* p1=nullptr;
        TreeNode* p2=nullptr;
        
        search(root,target1,p1);
        search(root,target2,p2);
        
        p1->val=target2;
        p2->val=target1;
    }
    
    void search(TreeNode* root, int target, TreeNode* &ptr){
        if(root!=nullptr){
            if(root->val==target)
                ptr=root;
            else{
                search(root->left,target,ptr);
                search(root->right,target,ptr);
            }
        }
    }
    
    void help(TreeNode* root, vector<int> &v1){
        if(root!=nullptr){
            help(root->left,v1);
            v1.push_back(root->val);
            help(root->right,v1);
        }
    }
    
};
