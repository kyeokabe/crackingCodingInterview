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
    int maxDepth(Node* root) {
        if (root==nullptr)
            return 0;
        int depth=0;
        int count=1;
        help(root, count, depth);
        return depth;
    }
    
    void help(Node* root, int count, int &depth){
        if (count>depth)
            depth=count;
        count+=1;
        for (int i=0;i<root->children.size();i++)
            help(root->children[i],count,depth);
    }
};
