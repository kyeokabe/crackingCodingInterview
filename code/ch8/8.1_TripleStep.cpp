//8.1
//write a recursive function that counts possible ways to climb n steps
//you can choose to hop 1, 2, or 3 at a time. count 0 steps as 1 way.

#include <iostream>
#include<stdio.h>
using namespace std;

int CountPaths(int N);

int main() {
    
    int a=4;
    //int count=0;
    //int foo[]={};
    int c=0;
    c=CountPaths(a);
    printf ("Answer is %d\n", c);
    return 0;
}

int CountPaths(int N){
    if (N<0)
        return 0;
    if (N==0)
        return 1;
    return CountPaths(N-3)+CountPaths(N-2)+CountPaths(N-1);
}
