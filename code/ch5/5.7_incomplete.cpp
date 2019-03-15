//5.7 ... Pairwise Swap (incomplete)
//write a function to swap even and odd bits with minimum instructions as possible.

/*
all about knowing the & operator
*/

#include <iostream>
#include<stdio.h>
using namespace std;

int bitswapEvenOdd(int a, int b[]);

int binary_digits(int a);
int arrayToBinary(int b[], int sizeofb);

/*
0101
1010
 */
int main() {
    int a=3;
    int a_size;
    a_size=binary_digits(a);
    int b[a_size+1];
    //technically don't need to initialize
    for (int i=0;i<a_size+1;i++)
        b[i]=0;
    int sizeOfb = sizeof(b)/sizeof(b[0]);

    cout<<"size of b = "<<sizeOfb<<endl;
    
    bitswapEvenOdd(a,b);
    
    cout<<"b[0] = "<<b[0]<<endl;
    
    cout<<"answer is: "<<arrayToBinary(b, sizeOfb)<<endl;
    return arrayToBinary(b, sizeOfb);

}

int binary_digits(int a){
    if (a<=0)
        return 0;
    
    int count=0;
    
    while(a!=0){
        a=a/2;
        count++;
    }
    return count;
}


int bitswapEvenOdd(int a,int b[]){
    int i=0;
    if (a==0)
        return 0;
    while (a!=0){
        if ((a%2==1) && (a%4==1)){
            b[i]=0;
            b[i+1]=0;
        }
        if ((a%2==1) && (a%4==0)){
            b[i]=0;
            b[i+1]=1;
        }
        if ((a%2==0) && (a%4==1)){
            b[i]=1;
            b[i+1]=0;
        }
        if ((a%2==0) && (a%4==0)){
            b[i]=1;
            b[i+1]=1;
        }
        a=a/4;
        i=i+2;
    }
    return 0;
}

int arrayToBinary(int b[], int sizeOfb){
    int foo=0;
    int count=0;
    
    if (b[0]==1)
        foo=1;
    
    for (int i=1;i<sizeOfb;i++){
        if (b[i]==1)
            foo=foo+2*count;
        count++;
    }
    return foo;
}
