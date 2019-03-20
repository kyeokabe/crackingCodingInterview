//2.8 incomplete

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
        head=nullptr;
    }
    
    void addToRear(string foo){
        Node *temp;
        temp=head;
        
        while (temp!=nullptr){
            temp=temp->next;
        }
        Node *p;
        p = new Node;
        p->treasure=foo;
        p->next=nullptr;
        temp->next=p;
    }
    
    /*
    void deleteItem(string foo){
        
    }
    */
    
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
    foo.addToRear("gimmick1");
    foo.addToRear("gimmick2");
    foo.addToRear("gimmick3");
    foo.addToRear("gimmick4");
    foo.addToRear("gimmick5");
    foo.printItems();
    return 0;
}
