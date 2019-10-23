/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)
            return nullptr;
        
        unordered_map<Node*,Node*> m;
        copyFirstPass(head,m); // deep copy of LL w/o next and random assigned
        copySecondPass(head,m); //assign next to deep copy of LL
        copyThirdPass(head,m);
        return m[head];
    }
    
    void copyThirdPass(Node* head, unordered_map<Node*,Node*> &m){
        if(head==nullptr)
            return;
        else{
            if(head->random==nullptr){
                auto it=m.find(head);
                it->second->random=nullptr;
            }
            else{
                auto it=m.find(head->random);
                auto it2=m.find(head);
                it2->second->random=it->second;
            }
            head=head->next;
            copyThirdPass(head,m);
        }
    }
    
    void copySecondPass(Node* head, unordered_map<Node*,Node*> &m){
        if(head==nullptr)
            return;
        else{
            if(head->next!=nullptr){
                auto it=m.find(head->next);
                auto it2=m.find(head);
                it2->second->next=it->second;
                head=head->next;
                copySecondPass(head,m);
            }
        }
    }
    
    void copyFirstPass(Node* head, unordered_map<Node*,Node*> &m){
        if(head==nullptr)
            return;
        else{
            Node* ptr = new Node(head->val,nullptr,nullptr);
            m[head]=ptr;
            head=head->next;
            copyFirstPass(head,m);
        }
    }
};
