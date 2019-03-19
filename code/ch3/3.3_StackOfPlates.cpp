// 3.3 Stack of Plates

/*
 Should know how to make an array of classes.
 Dynamically allocated array?
 */

#include <iostream>
#include <stdio.h>
using namespace std;

const int SIZE=100;

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
        m_num_stacks=1;
    }
    
    int push(int a){
        
        
        
        return 0;
    }
    
private:
    int m_num_stacks;
    Stack foo;
};
