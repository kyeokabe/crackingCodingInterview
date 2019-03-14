//5.5 ... Debugger
//explain what ((n & (n-1)) == 0) does


/*
all about knowing the & operator
*/

#include <iostream>
#include<stdio.h>
using namespace std;


int main() {
    cout<<"8 & 7 = "<<(8&7)<<endl;
    cout<<"8 & 6 = "<<(8&6)<<endl;
    cout<<"8 & 4 = "<<(8&4)<<endl;
    cout<<"7 & 6 = "<<(7&6)<<endl<<endl;
    cout<<"a & b returns the equivalent number where the"<<endl;
    cout<<"\"1\" bits overlap in binary representation."<<endl<<endl;
    return 0;
}
