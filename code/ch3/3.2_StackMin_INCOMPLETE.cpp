// 3.2 Stack Min

/*
Should know how to make a class that uses its class.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

const int SIZE=100;

bool isUnique(string a);

//class Stack1;

class Stack{
public:
    Stack(){
        for (int i=0;i<SIZE;i++)
            m_array[i]=0;
        current_index=0;
        m_min_initialized=false;
    }
    
    ~Stack(){
        delete m_min_stack;
    }
    
    void push(int a){
        if (!m_min_initialized)
            m_min=a;
        if (m_min>a)
            m_min=a;
        m_array[current_index]=a;
        current_index++;
    }
    
    int pop(){
        current_index--;
        int temp=m_array[current_index];
        m_array[current_index]=0;
        return temp;
    }
    
private:
    int m_array[SIZE];
    int current_index;
    int m_min;
    bool m_min_initialized;
    Stack *m_min_stack;
};


int main() {
    
    Stack foo1;
    
    return 0;
}
