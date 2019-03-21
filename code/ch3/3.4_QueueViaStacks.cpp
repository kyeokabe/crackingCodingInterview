//3.4 Queue via Stacks

/*
Implement a MyQueue class which implements a queue using two stacks.
Not too difficult.
*/

#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

class MyQueue{
  
public:
    MyQueue(){
        currentStack=1;
    }
    
    void push(int foo){
        if (currentStack==1){
            a.push(foo);
        }
    }
    
    void pop(){
        while (!a.empty()){
            b.push(a.top());
            a.pop();
        }
        if (!b.empty())
            b.pop();
        while (!b.empty()){
            a.push(b.top());
            b.pop();
        }
        return;
    }
    
    int front(){
        while (!a.empty()){
            b.push(a.top());
            a.pop();
        }
        
        int foo=-1;
        if (!b.empty())
            foo=b.top();
        
        while (!b.empty()){
            a.push(b.top());
            b.pop();
        }
        return foo;
    }
    
    bool empty(){
        return (a.empty());
    }
    
private:
    stack<int> a;
    stack<int> b;
    int currentStack;
};



int main(){
    
    MyQueue foo;
    foo.push(0);
    foo.push(1);
    foo.push(2);
    foo.push(3);
    foo.pop();
    foo.push(4);
    
    while (!foo.empty()){
        cout<<foo.front()<<endl;
        foo.pop();
    }

    return 0;
}
