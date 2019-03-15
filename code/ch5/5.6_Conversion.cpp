//5.6 ... Conversion
//write a function to determine the number of bits you would need to flip to convert int A to int B
//eg. input: 29 (11101), 15 (01111) -> output: 2

/*
all about knowing the & operator
*/

#include <iostream>
#include<stdio.h>
using namespace std;

//elegant solution from book
/*
int bitswap(int a, int b){
    int count=0;
    for (int c=(a^b);c!=0;c = c>>1)
        count=count+(c&1);
    cout << count<<endl;
}
*/


int binary_digits(int a);
int overlap_digits(int a);

int main() {
    int a=15;
    int b=29;
    
    int a_size,b_size,maxdigit;
    
    a_size=binary_digits(a);
    b_size=binary_digits(b);
    int overlapdigit=overlap_digits((a&b));

    if (a_size>=b_size)
        maxdigit=a_size;
    else
        maxdigit=b_size;

    cout<<"input 1 = "<<a<<endl;
    cout<<"input 2 = "<<b<<endl<<endl;
    cout<<"max binary digit = "<<maxdigit<<endl;
    cout<<"overlap binary digits in decimal= "<<(a&b)<<endl;
    cout<<"overlaping binary digits = "<<overlapdigit<<endl;

    cout<<endl;
    cout<<"bits neededed to flip = "<<maxdigit-overlapdigit<<endl<<endl;
    
    return 0;
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

int overlap_digits(int a){
    if (a<=0)
        return 0;
    int count=0;
    while(a!=0){
        if (a%2==1){
            count++;
        }
        a=a/2;
    }
    return count;
}
