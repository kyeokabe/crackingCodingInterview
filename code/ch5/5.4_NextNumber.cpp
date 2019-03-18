//5.4 Next Number

/*
Given a positive integer, print the next smallest and
next largest number that have the same number of 1bits
in their binary representation.
 
 
assuming no negative numbers for next smallest number.
relatively easy and straight forward.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

void flipBit(int &a);

int get_1s(int a);
int nextBig(int a);
int nextSmall(int a);

int main(){
    int a = 52;
    cout<<"next biggest is: "<<nextBig(a)<<endl;
    //covers cases such as input = 1;
    //assuming no negative numbers;
    if (nextSmall(a)==0)
        cout<<"next small number non-existent"<<endl;
    else
        cout<<"next smallest is: "<<nextSmall(a)<<endl;
    return 0;
}

int get_1s(int a){
    int num_1s=0;
    while (a!=0){
        if (a%2==1)
            num_1s++;
        a=a/2;
    }
    return num_1s;
}

int nextBig(int a){
    bool found_nextBig=false;
    int target_1s=get_1s(a);
    
    while (!found_nextBig){
        a++;
        if (target_1s==get_1s(a))
            found_nextBig=true;
    }
    return a;
}

int nextSmall(int a){
    bool found_nextSmall=false;
    int target_1s=get_1s(a);
    
    while (!found_nextSmall || (a==0)){
        a--;
        if (target_1s==get_1s(a))
            found_nextSmall=true;
    }
    return a;
}
