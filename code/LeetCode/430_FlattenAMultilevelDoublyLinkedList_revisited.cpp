/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* ptr) {
        if(ptr==nullptr)
            return nullptr;
        queue<Node*> q;
        help(q,ptr);
        Node* ptr2=q.front();
        q.pop();
        while(!q.empty()){
            q.front()->prev=ptr2;
            ptr2->next=q.front();
            ptr2->child=nullptr;
            ptr2=q.front();
            q.pop();
        }
        ptr2->next=nullptr;
        ptr2->child=nullptr;
        return ptr;
    }
    
    void help(queue<Node*> &q, Node* ptr){
        if(ptr==nullptr)
            return;
        q.push(ptr);
        if(ptr->child!=nullptr)
            help(q,ptr->child);
        if(ptr->next!=nullptr)
            help(q,ptr->next);
    }
    
};
