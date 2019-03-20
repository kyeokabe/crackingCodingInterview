//2.8 incomplete ... basic working linked list

/*
 Given a circular linked list, implement an algorithm that returns
 the node at the beginning of the loop.
 */

#include <iostream>
#include <stdio.h>
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
    }
    
    void addToFront(string foo){
        Node *p;
        p = new Node;
        p->treasure = foo;
        
        p->next=head;
        head=p;
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
        return;
    }
    
    void printItems(){
        Node *temp;
        temp=head;
        if (temp==nullptr){
            cout<<"empty list"<<endl;
        }
        
        while (temp!=nullptr){
            cout<<temp->viewNode()<<endl;
            temp=temp->next;
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
};

int main() {
    
    LinkedList foo;
    //cout<<endl;
    foo.addToFront("gimmick1");
    foo.addToFront("gimmick2");
    foo.addToFront("gimmick3");
    foo.printItems();
    cout<<endl;
    foo.addToBack("gimmick4");
    foo.addToFront("gimmick5");
    foo.printItems();
    cout<<endl;
    return 0;
}
