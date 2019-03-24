//https://www.youtube.com/watch?v=D35llNtkCps
//https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-introduction-to-algorithms-sma-5503-fall-2005/video-lectures/lecture-6-order-statistics-median/lec6.pdf

#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

int smallest(int a[], int length);
int secondsmallest(int a[], int length);
void swap (int &a,int &b);

int main() {
    int a[6]={4,2,7,4,9,3};
    int length=sizeof(a)/sizeof(a[0]);
    cout<< " first smallest = " << smallest(a,length)<<endl;
    cout<<" second smallest = " << secondsmallest(a,length)<<endl;
    return 0;
}

int smallest(int a[], int length){
    int foo=a[0];
    for (int i=0;i<length;i++){
        if (a[i]<foo)
            foo=a[i];
    }
    return foo;
}


int secondsmallest(int a[], int length){
    int foo1=a[0];
    int foo2=a[1];
    
    if (foo2<foo1)
        swap (foo2, foo1);
    
    for (int i=2;i<length;i++){
        if (a[i]<foo2){
            foo2=a[i];
            if (foo2<foo1)
                swap (foo2, foo1);
        }
    }
    return foo2;
}

void swap (int &a,int &b){
    //a=12, b=7
    a=a-b; //a=5, b=7
    b=a+b; //a=5,b=12
    a=b-a; //a=7, b=12
}
