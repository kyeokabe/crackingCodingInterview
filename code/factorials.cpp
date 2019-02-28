//simple recursion example

#include <iostream>
#include<stdio.h>

int factorial(int N){
    if (N==0){
    return 1;
    }
    return N*factorial(N-1);
}

int main() {
    
    int N=5;
    int foo=factorial(N);
    
    printf ("Factorial of %d is %d \n", N, foo);
    return 0;
}
