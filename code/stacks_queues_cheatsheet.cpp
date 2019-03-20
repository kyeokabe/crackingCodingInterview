//queue and stack cheat sheet

#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;

int main() {
    
    queue<int> iqueue;
    iqueue.push(10);
    iqueue.push(5);
    iqueue.push(2);
    cout<<"10 5 2"<<endl;
    cout<<"front of queue: "<<iqueue.front()<<endl;
    iqueue.pop();
    cout<<"front of queue: "<<iqueue.front()<<endl;
    cout<<endl;
    cout<<"is queue empty? "<<iqueue.empty()<<endl;
    iqueue.pop();
    iqueue.pop();
    cout<<"is queue empty? "<<iqueue.empty()<<endl<<endl;
    cout<<"size of queue = "<<iqueue.size()<<endl<<endl;
    cout<<"####stacks####"<<endl<<endl;
    stack<int> istack;
    istack.push(5);
    istack.push(3);
    cout<<"5 3"<<endl;
    cout<<"top of stack:"<<istack.top()<<endl;
    istack.pop();
    cout<<"top of stack:"<<istack.top()<<endl;
    cout<<"is stack empty? "<<istack.empty()<<endl;
    istack.pop();
    cout<<"is stack empty? "<<istack.empty()<<endl;
    
    return 0;
}
