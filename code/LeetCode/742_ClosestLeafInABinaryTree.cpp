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
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*,TreeNode*> m;
        unordered_map<TreeNode*,TreeNode*> traveled;
        TreeNode* target=nullptr;
        mapChild2Parent(m,root);
        findTarget(root,target,k);
        queue<TreeNode*> q;
        q.push(target);
        return help(q,m,traveled);
    }
    
    void mapChild2Parent(unordered_map<TreeNode*,TreeNode*> &m,TreeNode* root){
        if(root->left!=nullptr){
            m[root->left]=root;
            mapChild2Parent(m, root->left);
        }
        if(root->right!=nullptr){
            m[root->right]=root;
            mapChild2Parent(m, root->right);
        }   
    }
    
    void findTarget(TreeNode* &root, TreeNode* &target, int &k){
        if(root->val==k){
            target=root;
            return;
        }
        else{
            if(root->left!=nullptr)
                findTarget(root->left,target,k);
            if(root->right!=nullptr)
                findTarget(root->right,target,k);
        }
    }
    
    int help(queue<TreeNode*> q, unordered_map<TreeNode*,TreeNode*> m, unordered_map<TreeNode*,TreeNode*> traveled){
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                if(q.front()->left==nullptr&&q.front()->right==nullptr)
                    return q.front()->val;
                else{
                    //if there is a parent node and it has not been traveled, add to queue
                    auto it=m.find(q.front());
                    if(it!=m.end()){
                        auto it2=traveled.find(it->second);
                        if(it2==traveled.end()){
                            traveled[it->second]=it->second;
                            q.push(it->second);
                        }
                    }
                    //if there is a left child and it has not been traveled, add to queue
                    if(q.front()->left!=nullptr){
                        auto it_l=traveled.find(q.front()->left);
                        if(it_l==traveled.end()){
                            traveled[q.front()->left]=q.front()->left;
                            q.push(q.front()->left);
                        }
                    }
                
                    //if there is a right child and it has not been traveled, add to queue
                    if(q.front()->right!=nullptr){
                        auto it_r=traveled.find(q.front()->right);
                        if(it_r==traveled.end()){
                            traveled[q.front()->right]=q.front()->right;
                            q.push(q.front()->right);
                        }
                    }
                
                }
                q.pop();
            }
        }
            return 0;
    }

    
};
