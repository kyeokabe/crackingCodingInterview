//2.6 Palindrome
/*
Implement a function to check if a linked list is a palindrome.
 
//using stacks and queues made this easy.
//assumed API had access to traverse Linked List
//assumed empty LL is a palindrome
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
    
    //assuming a LL w/o Node is a palindrome
    bool isPalindrome(){
        Node *temp;
        temp=head;
        
        queue<string> iqueue;
        stack<string> istack;
        bool isPalindrome=true;
        while(temp!=nullptr){
            iqueue.push(temp->treasure);
            istack.push(temp->treasure);
            temp=temp->next;
        }
        
        while(!iqueue.empty()){
            if (iqueue.front()!=istack.top())
                isPalindrome=false;
            iqueue.pop();
            istack.pop();
        }
        return isPalindrome;
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
    
    LinkedList foo1,foo2;
    //cout<<endl;
    foo1.addToFront("gimmick1");
    foo1.addToFront("gimmick2");
    foo1.addToFront("gimmick3");
    foo1.addToBack("gimmick4");
    foo1.addToFront("gimmick5");
    foo1.printItems();
    cout<<endl;
    cout<<"is palindrome? = "<<foo1.isPalindrome()<<endl<<endl;
    
    foo2.addToFront("gimmick1");
    foo2.addToFront("gimmick2");
    foo2.addToFront("gimmick3");
    foo2.addToFront("gimmick2");
    foo2.addToFront("gimmick1");
    foo2.printItems();
    cout<<endl;
    cout<<"is palindrome? = "<<foo2.isPalindrome()<<endl<<endl;
    return 0;
}
