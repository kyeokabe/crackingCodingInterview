/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(head==nullptr)
            return nullptr;
        queue<Node*> q;   
        help(q,head);
        Node* temp=q.front();
        while(!q.empty()){
            temp=q.front();
            temp->child=nullptr;
            q.pop();
            if(!q.empty()){
                temp->next=q.front();
                q.front()->prev=temp;
            }
        }
        temp->child=nullptr;
        temp->next=nullptr;
        head->prev=nullptr;
        return head;
    }
    
    void help(queue<Node*> &q, Node* ptr){
        while(ptr!=nullptr){
            q.push(ptr);
            if(ptr->child!=nullptr){
                help(q,ptr->child);
            }
            ptr=ptr->next;
        }
    }
};
