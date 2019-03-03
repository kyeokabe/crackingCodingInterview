//8.5
//write a recursive function to multiply two positive integers w/o using
//the * operator. +, -, bit shift is OK. minimize operations.

#include <iostream>
#include<stdio.h>
using namespace std;

int RecursiveMultiply(int a, int b);

int main() {
    
    int a=7;
    int b=-2;
    
    //int foo[]={};
    int c=0;
    c=RecursiveMultiply(a, b);
    printf ("Answer is %d\n", c);
    return 0;
}

int RecursiveMultiply(int a, int b){
    //cout<<a<<"foo3\n";
    if ((a || b) == 0){
        //cout<<a<<"foo\n";
        return 0;
    }
    if (a==1)
        return b;
    if (b==1)
        return a;
    if (a==-1)
        return -b;
    if (b==-1)
        return -a;
    if ((abs(a) < abs(b)) && (a < 0))
        return -b+RecursiveMultiply(a+1,b);
    if ((abs(a) < abs(b)) && (a > 0))
        return b+RecursiveMultiply(a-1,b);
    if ((abs(a) > abs(b)) && (b > 0))
        return a+RecursiveMultiply(a,b-1);
    if ((abs(a) > abs(b)) && (b < 0))
        return -a+RecursiveMultiply(a,b+1);
    return -1;
}
