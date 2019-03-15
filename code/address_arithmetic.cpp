#include <iostream>
#include<stdio.h>
using namespace std;

/*
0101
1010
 */
int main() {
    int b[6]={5,1,9,8,4,6};
    int *ptr=&b[2];
    
    
    cout<<"address of b[0]: "<<&b[0]<<endl;
    cout<<"address of b[1]: "<<&b[1]<<endl;
    cout<<"address of b[2]: "<<&b[2]<<endl;
    cout<<"address of b[3]: "<<&b[3]<<endl;
    cout<<"address of b[4]: "<<&b[4]<<endl<<endl;

    cout<<"address of ptr: "<<ptr<<endl;
    cout<<"address of ptr++: "<<(ptr++)<<endl;
    cout<<"address of ptr+1: "<<(ptr+1)<<endl<<endl;
    
    cout<<"address arithmetic: "<<(&b[1]+1)<<endl<<endl;


    cout<<"addresses are segmented by bytes, not bits!"<<endl;
    cout<<"one int is 32 bits!"<<endl<<endl;

}
