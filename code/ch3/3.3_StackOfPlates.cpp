// 3.3 Stack of Plates

/*
 have not tested code yet.
 Should know how to make an array of classes.
 
 assuming maximum of 100 stacks of stacks
 */

#include <iostream>
#include <stdio.h>
using namespace std;

const int SIZE=100;
const int MAX_STACK_NUM=10;

//class Stack;
class Stack{
public:
    Stack(){
        for (int i=0;i<SIZE;i++)
            m_array[i]=0;
        m_index=0;
    }
    
    void push(int a){
        if (m_index<SIZE-1){
            m_array[m_index]=a;
            m_index++;
        }
    }
    
    int pop(){
        if (m_index>0){
            int temp=m_array[m_index-1];
            m_array[m_index-1]=0;
            m_index--;
            return temp;
        }
        return -1;
    }
    
    bool is_empty(){
        if (m_index==0)
            return true;
        return false;
    }

    bool is_full(){
        if (m_index==SIZE)
            return true;
        return false;
    }
    
    int peek_top(){
        if (m_index==0)
            return -1;
        return m_array[m_index-1];
    }
    
private:
    int m_array[SIZE];
    int m_index;
};


//class Stack;
class SuperStack{
public:
    SuperStack(){
        m_stack_index=0;
    }
    
    void push(int a){
        if (foo[m_stack_index].is_full()){
            m_stack_index++;
            if (m_stack_index<MAX_STACK_NUM)
                foo[m_stack_index].push(a);
            else
                cout<<"maximum num of stacks reached"<<endl;
        }
        else
            foo[m_stack_index].push(a);
    }
    
    void pop(){
        if ((m_stack_index==0) && (foo[m_stack_index].is_empty())){
            cout <<"stack is empty"<<endl;
            return;
        }
        if (foo[m_stack_index].is_empty()){
            m_stack_index--;
            foo[m_stack_index].pop();
            return;
        }
        foo[m_stack_index].pop();
        return;
    }
    
private:
    int m_stack_index;
    Stack foo[MAX_STACK_NUM];
};
