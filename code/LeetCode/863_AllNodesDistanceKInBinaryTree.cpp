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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*,TreeNode*> m;
        unordered_map<TreeNode*,TreeNode*> visited;

        help(root,m);
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=target;
        int level=0;
        int qsize=q.size();
        
        while(level!=K){
            
            for(int i=0;i<qsize;i++){
                if(q.front()->left!=nullptr){
                    auto it=visited.find(q.front()->left);
                    if(it==visited.end()){
                        q.push(q.front()->left);
                        visited[q.front()->left]=q.front()->left;
                    }
                }
                if(q.front()->right!=nullptr){
                    auto it=visited.find(q.front()->right);
                    if(it==visited.end()){
                        q.push(q.front()->right);
                        visited[q.front()->right]=q.front()->right;
                    }
                }
                auto it=m.find(q.front());
                if(it!=m.end()){
                    auto itit=visited.find(it->second);
                    if(itit==visited.end()){
                        visited[it->second]=it->second;
                        q.push(it->second);
                    }
                }

                q.pop();
            }
            qsize=q.size();
            level++;
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
    
    void help(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &m){
        if(root==nullptr)
            return;
        if(root->right!=nullptr){
            m[root->right]=root;
            help(root->right,m);
        }
        if(root->left!=nullptr){
            m[root->left]=root;
            help(root->left,m);
        }
    }
};
