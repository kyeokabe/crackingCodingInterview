//adapted from Cris_Tang
//https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/discuss/149151/Concise-Java-solution-Beats-100

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:
    Node* temp;
public:
    Node* treeToDoublyList(Node* root) {
        if(root==nullptr)
            return nullptr;
        Node* head=root;
        Node* tail=root;
        while(head->left!=nullptr)
            head=head->left;
        while(tail->right!=nullptr)
            tail=tail->right;
        Node* dummy=new Node(0,nullptr,nullptr);
        temp=dummy;
        help(root);
        head->left=tail;
        tail->right=head;
        return head;
    }
    
    void help(Node* ptr){
        if(ptr==nullptr)
            return;
        help(ptr->left);
        temp->right=ptr;
        ptr->left=temp;
        temp=ptr;
        help(ptr->right);
    }
    
};
