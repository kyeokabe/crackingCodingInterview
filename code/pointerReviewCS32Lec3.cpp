//pointer review from CS32 Lec 3 ... take note on "very confusing" example

#include <iostream>
#include<stdio.h>
using namespace std;

void basicPointer(int* y1){
    *y1=2;
}

void veryConfusiong(int &y2){
    y2=4;
}

int main (){
    int x1=1;
    int x2=3;
    
    cout<<"Basic pointer example: x1 (before) = "<<x1<<"\n";
    basicPointer(&x1);
    cout<<"Basic pointer example: x1 (after) = "<<x1<<"\n";
    cout<<"\n";
    
    //note x2 being passed "raw"
    cout<<"Very confusing example: x2 (before) = "<<x2<<"\n";
    veryConfusiong(x2);
    cout<<"Very confusing example: x2 (after) = "<<x2<<"\n";
    cout<<"\n";
    return 0;
}
