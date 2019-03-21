//2.2 Return Kth to Last
/*
Implement an algorithm to find the kth
to last element of a singly linked list.

//not too difficult if using stacks
 
*/

#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

class Node{
public:
    string viewNode(){
        return treasure;
    }
    Node *next;
    
    string treasure;
    
private:
};

class LinkedList{
public:
    LinkedList(){
        head = nullptr;
        num_nodes=0;
    }
    
    string Kth2Last(int k){
        stack<Node*> NodeStack;
        Node* temp;
        temp=head;
        
        while(temp!=nullptr){
            NodeStack.push(temp);
            temp=temp->next;
        }
        
        for (int i=1;i<k;i++){
            NodeStack.pop();
        }
        
        return NodeStack.top()->treasure;
    }
    
    void addToFront(string foo){
        Node *p;
        p = new Node;
        p->treasure = foo;
        p->next=head;
        head=p;
        num_nodes++;
    }
    
    void addToBack(string foo){
        if (head==nullptr){
            addToFront(foo);
            return;
        }
        Node *p,*temp;
        temp=head;
        p = new Node;
        p->treasure=foo;
        
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=p;
        p->next=nullptr;
        num_nodes++;
        return;
    }

    void printItems(){
        Node *temp;
        temp=head;
        if (temp==nullptr){
            cout<<"empty list"<<endl;
        }
        
        int count=0;
        while (temp!=nullptr && count<num_nodes){
            cout<<temp->viewNode()<<endl;
            temp=temp->next;
            count++;
        }
    }
    
    ~LinkedList(){
        Node *temp1,*temp2;
        temp1=head;
        while(temp1!=nullptr){
            temp2=temp1->next;
            delete temp1;
            temp1=temp2;
        }
    }
    
    
private:
    Node *head;
    int num_nodes;
    
};

int main() {
    
    LinkedList foo1;
    foo1.addToFront("gimmick1");
    foo1.addToFront("gimmick2");
    foo1.addToFront("gimmick3");
    foo1.addToBack("gimmick4");
    foo1.addToFront("gimmick5");
    foo1.addToBack("gimmick6");

    foo1.printItems();
    cout<<endl<<"kth from back"<<foo1.Kth2Last(3)<<endl<<endl;
    
    return 0;
}
