//5.2 Binary to String

/*
Given a real number between 0 and 1 (e.g., 0.72) passed in as a double,
print the binary representation. If the number cannot be represented accurately
in binary with at most 32 characters, print "ERROR."
*/

#include <iostream>
#include <stdio.h>
using namespace std;

void printBinary (double a);

int main(){
    
    double a = 0.32958984375;
    
    printBinary(a);
    return 0;
}

void printBinary (double a){
    int b[32];
    
    for (int i=0;i<32;i++)
        b[i]=0;
    double temp=0;
    double temp2=1.0;
    bool complete=false;
    
    for (int i=0;i<32;i++){
        if (temp==a){
            complete=true;
            break;
        }
        temp2=temp2/2.0;
        if (a>=temp+temp2){
            b[i]=1;
            temp=temp+temp2;
            if (temp==a)
                complete=true;
        }
    }
    if (complete ==false)
        cout<<"ERROR"<<endl;
    else{
        cout<<"0.";
        for (int i=0;i<32;i++){
            cout<<b[i];
        }
    }
    cout<<endl;
}
