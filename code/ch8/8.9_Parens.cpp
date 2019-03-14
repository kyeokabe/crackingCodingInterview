//8.9 implement an algorithm to print all valid combinations of n pairs of parentheses

#include <iostream>
#include<stdio.h>
using namespace std;

void printParentheses(int N);

//given int N, return highest digit in binary representation
//e.g. 7~4 is 3, 15~8 is 4 etc.
int highest_binary_digit(int N);

//given int N, returns number of digits with a "1" in binary representation
//e.g. 15 is 4, 7 is 3 etc.
int num_of_1_digits(int N);

//given int N, returns bool whether number of digits with a "0"
//in binary representation equals number of digits with a "1"
bool num_of_0_digits_equals_1_digits(int N);

//given int N, returns bool whether in binary representation there are always
//more than or equal "1" bits to the left at any given bit
bool more_1s_on_left(int N);

//given int N, print "(" where binary digit is 1 and ")" where binary digit is 0
// e.g., N=5="101" ... N=5 prints "()("
void num_to_parenth_print(int N);

//given int N, if binary representation is 1 in m th digit, return 1
//given int N, if binary representation is 0 in m th digit, return 0
// e.g., N=5="101" ... N=5,m=1 is 1, N=5,m=2 is 0, N=5,m=3 is 1
int mod_m(int N, int m);

//given int N, return 2^N
// e.g. N=1 returns 4, N=2 returns 16, N=3 returns 64 etc.

int powerN(int N);

/*
 functions not used
 */



//same as above without using recursion. Works, but not used.
int num_of_1_digits_non_recursion(int N);

/*
end functions not used
 */
 
int main() {

    int N=3;//change N freely (input);
    printParentheses(N);
    cout << endl;
    return 0;
}

void printParentheses(int N){
    int bin_paren_rep=powerN(N);
    //cout <<bin_paren_rep<<endl<<endl;
    for (int i=0; i<bin_paren_rep;i++){
        if (num_of_1_digits(i)==N){
            //cout << i << endl;
            if (num_of_0_digits_equals_1_digits(i)){
                //cout <<"foo"<< i << endl;
                if (more_1s_on_left(i))
                    if (i>0){
                        num_to_parenth_print(i);
                        cout<<", ";
                    }
            }
        }
    }
}

//given int N, return highest digit in binary representation
//e.g. 7~4 is 3, 15~8 is 4 etc.
int highest_binary_digit(int N){
    if (N<=0)
        return 0;
    return 1+ highest_binary_digit(N/2);
}

//given int N, returns number of digits with a "1" in binary representation
//e.g. 15 is 4, 7 is 3 etc.
int num_of_1_digits(int N){
    if (N<=0)
        return 0;
    if (N%2==1)
        return 1+num_of_1_digits(N/2);
    
    return num_of_1_digits(N/2);
}

//given int N, returns bool whether number of digits with a "0"
//in binary representation equals number of digits with a "1"
bool num_of_0_digits_equals_1_digits(int N){
    return (highest_binary_digit(N)==2*num_of_1_digits(N));
}

bool more_1s_on_left(int N){
    int count_1=0;
    int count_0=0;
    int Max_digit=highest_binary_digit(N);
    int m=Max_digit;
    for (int i=1;i<=Max_digit; i++){
        if (mod_m(N,m)==1)
            count_1++;
        if (mod_m(N,m)==0)
            count_0++;
        m--;
        if (count_0>count_1)
            return false;
    }
    return true;
}

//given int N, print "(" where binary digit is 1 and ")" where binary digit is 0
// e.g., N=5="101" ... N=5 prints "()("
void num_to_parenth_print(int N){
    int Max_digit=highest_binary_digit(N);
    int m=Max_digit;
    for (int i=1;i<=Max_digit; i++){
        if (mod_m(N,m)==1)
            cout<<"(";
        if (mod_m(N,m)==0)
            cout<<")";
        m--;
    }
}

//given int N, if binary representation is 1 in m th digit, return 1
//given int N, if binary representation is 0 in m th digit, return 0
// e.g., N=5="101" ... N=5,m=1 is 1, N=5,m=2 is 0, N=5,m=3 is 1
int mod_m(int N, int m){
    return ((N>>(m-1))%2); // x>>y bitshifts x, y times to the "smaller" side
}

//given int N, return 2^N
// e.g. N=1 returns 4, N=2 returns 16, N=3 returns 64 etc.
// return 2^(2*N)
int powerN(int N){
    if (N==0)
        return 1;
    if (N==1)
        return 4;
    int foo=2;
    for (int i=1;i<2*N;i++)
        foo=foo*2;
    return foo;
}

//given int N, returns number of digits with a "1" in binary representation
//implemented without recurrsion.

//Works, but don't need.
int num_of_1_digits_non_recursion(int N){
    int max_dig=highest_binary_digit(N);
    int count =0;
    for (int i=1;i<=max_dig;i++){
        if (mod_m(N,0)==1)
            count++;
        N=N>>1;
    }
    return count;
}
