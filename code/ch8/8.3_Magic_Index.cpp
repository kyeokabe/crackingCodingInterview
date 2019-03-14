//8.3 ... Magic Index
//given an array, find all A[i]=i elements


/*
Not interesting...
*/

#include <iostream>
#include<stdio.h>
using namespace std;


int main() {
    int foo[10]={0,9,6,3,2,1,5,9,7,8};
    int length=sizeof(foo)/sizeof(foo[0]);
    
    for (int i=0;i<length;i++)
        if (foo[i]==i)
            cout<<i<<endl;
    return 0;
}
