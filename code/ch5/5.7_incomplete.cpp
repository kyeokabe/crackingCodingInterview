//5.7 ... Pairwise Swap (incomplete)
//write a function to swap even and odd bits with minimum instructions as possible.

/*
Made several small errors. More of a grit problem.
Exponentials can be obtained by
 
#include <math.h>
 int foo = pow(2,3);
*/

#include <iostream>
#include<stdio.h>
#include <math.h>
using namespace std;

void bitswapEvenOdd(int a, int b[]);

int get_num_bin_digits(int a);
int arrayToBinary(int b[], int sizeofb);

/*
 0101
 1010
 */
int main() {
    int a=5;
    int a_num_digits;
    a_num_digits=get_num_bin_digits(a);
    int b[a_num_digits+1];
    //technically don't need to initialize
    for (int i=0;i<a_num_digits+1;i++)
        b[i]=0;
    cout<<"input = "<<a<<endl;
    cout<<"bin digits needed = "<<a_num_digits+1<<endl;
    
    bitswapEvenOdd(a,b);
    
    cout<<"reversed binary representation: ";
    for (int i=0;i<a_num_digits+1;i++)
        cout<<b[i];
    cout<<endl;
    
    cout<<"answer is: "<<arrayToBinary(b, a_num_digits+1)<<endl<<endl;
    return 0;
    
}

int get_num_bin_digits(int a){
    if (a<=0)
        return 0;
    int count=0;
    while(a!=0){
        a=a/2;
        count++;
    }
    return count;
}


void bitswapEvenOdd(int a,int b[]){
    int i=0;
    if (a==0)
        return;

    while (a!=0){
        if ((a%2==1) && ((a/2)%2==1)){
            b[i]=1;
            b[i+1]=1;
        }
        if ((a%2==1) && ((a/2)%2==0)){
            b[i]=0;
            b[i+1]=1;
            cout<<"i = "<<i<<", a = "<<a<<endl;

        }
        if ((a%2==0) && ((a/2)%2==1)){
            b[i]=1;
            b[i+1]=0;

        }
        if ((a%2==0) && ((a/2)%2==0)){
            b[i]=0;
            b[i+1]=0;
        }
        a=a/2;
        a=a/2;
        i=i+2;
    }
}

int arrayToBinary(int b[], int sizeOfb){
    int foo=0;
    int count=1;
    
    if (b[0]==1)
        foo=1;
    
    for (int i=1;i<sizeOfb;i++){
        if (b[i]==1)
            foo=foo+pow(2,count);
        count++;
    }
    return foo;
}
