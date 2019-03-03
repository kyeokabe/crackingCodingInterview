//write a recursion function that calculates the sum of int elements ... CS32 Lec 8 problem

#include <iostream>
#include<stdio.h>

int elementSum(int* N, int size);

int main() {
    
    int foo[5]={2,9,7,4,1};
    //int foo[]={};

    int size_array = sizeof(foo)/sizeof(foo[0]);
    
    printf ("Size of array is %d\n", size_array);
    
    int fooSum=elementSum(foo, size_array);
    printf ("\n");
    printf ("Sum of array is %d\n", fooSum);
    return 0;
}

int elementSum(int* N, int size_array){
    
    printf ("%d\n", N[0]);
    if (size_array==0)
        return 0;
    if (size_array==1)
        return N[0];
    return (N[0] + elementSum(N+1, size_array-1));
}
