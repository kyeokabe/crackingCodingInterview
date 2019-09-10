/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        vector<int> foo;
        //cout<<"foo = "<<root->val<<endl;
        foo.push_back(root->val);
        ans.push_back(foo);
        queue<Node*> q;
        for(int i=0;i<root->children.size();i++)
            q.push(root->children[i]);
        LO(ans,q);
        return ans;
    }
    
    void  LO(vector<vector<int>>& ans, queue<Node*> q){
        if(q.empty())
            return;
        vector<int> foo;
        queue<Node*> q2;
        while(!q.empty()){
            for(int i=0;i<q.front()->children.size();i++)
                q2.push(q.front()->children[i]);
            foo.push_back(q.front()->val);
            q.pop();
            }
        ans.push_back(foo);
        LO(ans,q2);
    }
        
        
};
