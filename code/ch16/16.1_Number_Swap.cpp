// 16.1 Write a function to swap a number in place (without temporary variables).

#include <iostream>
#include <stdio.h>
using namespace std;

void swap(int a, int b);

int main() {

    int a=5;
    int b=17;
    
    swap(a,b);
    
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    return 0;
}

void swap(int &a, int &b){
    b=b-a;
    a=a+b;
    b=a-b;
}
