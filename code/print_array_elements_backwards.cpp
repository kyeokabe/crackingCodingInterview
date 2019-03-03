//write a recursive function called printArr that prints
//out an array of intergers in reverse from bottom to top

#include <iostream>
#include<stdio.h>

void printArr(int* N, int size);

int main() {
    
    int foo[6]={2,9,7,4,1,8};
    //int foo[]={};

    int size_array = sizeof(foo)/sizeof(foo[0]);
    
    printf ("Size of array is %d\n\n", size_array);
    
    printArr(foo+size_array-1, size_array);
    printf ("\n");
    return 0;
}

void printArr(int* N, int size_array){
    //printf ("%d\n", N[0]);
    if (size_array==0)
        printf ("no elements");
    if (size_array==1){
        printf ("%d\n", N[0]);
        return;}
    printf ("%d\n", N[0]);
    printArr(N-1, size_array-1);
}
