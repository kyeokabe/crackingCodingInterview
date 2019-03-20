//2.8 Loop Detection

/*
 Given a circular linked list, implement an algorithm that returns
 the node at the beginning of the loop.
 
 //Interesting question. Kind of relies on whether you know the trick or not.
 //trick: two node ptrs. one travels 2 steps, the other 1 step. do they match?
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
        num_nodes=0;
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
    
    //assuming at least one element is in the LL
    void addCircular(string foo){
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
        p->next=head;
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
    
    bool isCircular(){
        Node *ptr1,*ptr2;
        ptr1 = head;
        ptr2 = head;

        if (ptr1 == nullptr || ptr2 ==nullptr){
            cout<<"foo"<<endl;
            return false;
        }
        if (ptr1->next==nullptr|| ptr2->next == nullptr)
            return false;
        while (ptr1!=nullptr){
            ptr1=ptr1->next->next;
            ptr2=ptr2->next;
            if (ptr1==ptr2)
                return true;
        }
        return false;
    }
    
private:
    Node *head;
    int num_nodes;
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
    foo.addCircular("gimmick6");
    foo.printItems();
    cout<<endl;
    cout<<"is circular? = "<<foo.isCircular()<<endl<<endl;

    int input;
    cout<<"the following cin >> is to prevent ";
    cout<<"input int: ";
    cout<<"the destructor from acting up."<<endl;
    cin>>input;
    
    cout<<endl;
    return 0;
}
