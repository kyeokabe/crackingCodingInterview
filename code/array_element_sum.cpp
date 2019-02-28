//incorrect... needs work

#include <iostream>
#include<stdio.h>

int elementSum(int N[]){
    
    int no_of_elements=sizeof(N)/sizeof(N[0]);
    if (no_of_elements==1)
    return N[0];
    
    return (N[no_of_elements-1]+elementSum(N[no_of_elements-2]));
}

int main() {
    
    int foo[5]={2,9,7,4,0};
    
    int fooSum=elementSum(foo);
    
    printf ("Sum of array is %d\n", fooSum);
    return 0;
}
