//5.3 Flip Bit to Win

/*
You have an integer and you can flip exactly one bit from a 0 to a 1.
Write code to find length of the longest sequence of 1s you could create.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

void flipBit(int &a);

int main(){
    
    int a = 52;
    
    flipBit(a);
    return 0;
}

void flipBit (int &a){
    int getDigits=0;
    int temp=a;
    int temp2=a;
    
    while (temp!=0){
        temp=temp/2;
        getDigits++;
    }
    
    int b[getDigits];
    
    for (int i=0;i<getDigits;i++){
        b[i]=0;
        if ((temp2%2) == 1){
            b[i]=1;
        }
        temp2=temp2/2;
    }
    
    
}
