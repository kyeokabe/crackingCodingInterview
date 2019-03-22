//2.1 Remove Dups
/*
Write code to remove duplicates from an unsorted linked list.
How would you solve this problem if
a temporary buffer is not allowed?

 
hard to code without a single error
this was a good problem to learn how to use the debugger
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
};

class LinkedList{
public:
    LinkedList(){
        head = nullptr;
        num_nodes=0;
    }
    
    void RemoveDups(){
        Node *temp1;
        Node *temp2;
        temp1=head;
        temp2=nullptr;
        while (temp1!=nullptr){
            temp2=temp1;
            while (temp2!=nullptr){
                if(temp2==temp1)
                    temp2=temp2->next;
                if(temp2!=nullptr && temp1->treasure==temp2->treasure){
                    swapNode(temp1);
                }
                if (temp2!=nullptr)
                    temp2=temp2->next;
            }
            if (temp1!=nullptr)
                temp1=temp1->next;
        }
    }
    
    void swapNode(Node* a){
        Node *temp1,*temp2;
        temp1=head;
        while (temp1->next!=a)
            temp1=temp1->next;
        temp2=temp1->next->next;
        delete a;
        
        temp1->next=temp2;
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
    foo1.addToBack("gimmick1");
    foo1.addToBack("gimmick4");
    foo1.addToBack("gimmick3");
    foo1.addToBack("gimmick4");
    foo1.addToBack("gimmick5");
    foo1.addToBack("gimmick6");
    foo1.addToFront("gimmick2");

    cout<<"pre-remove dups"<<endl;
    foo1.printItems();

    foo1.RemoveDups();
    cout<<endl<<endl;
    cout<<"post-remove dups"<<endl;
    foo1.printItems();
    
    return 0;
}
