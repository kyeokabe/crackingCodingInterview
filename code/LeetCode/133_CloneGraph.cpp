/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return nullptr;
        unordered_map<Node*,Node*> m;
        //deep copied the graph, need to fill ptr vectors though 
        
        vector<Node*> temp(node->neighbors.size(),nullptr);
        Node* ptr=new Node(node->val,temp);
        m[node]=ptr;
        help(node,m);
        
        auto it=m.begin();
        while(it!=m.end()){
            for(int i=0;i<it->first->neighbors.size();i++)
                it->second->neighbors[i]=m[it->first->neighbors[i]];
            it++;
        }
        return m[node];
    }
    
    void help(Node* node,unordered_map<Node*,Node*> &m){
        for(int i=0;i<node->neighbors.size();i++){
            if(m.find(node->neighbors[i])==m.end()){
                vector<Node*> temp(node->neighbors[i]->neighbors.size(),nullptr);
                Node* ptr = new Node(node->neighbors[i]->val,temp);
                m[node->neighbors[i]]=ptr;
                help(node->neighbors[i],m);
            }
        }
    }
};
