//very basics of pointers

#include <iostream>
#include<stdio.h>

void sum(int,int,int*);

int FuncPointArray(int array[]);

int main(void)
{
    int fooarray[5]={1,2,3,4,5};
    int *p;
    int i=5;
    p = &i;
    *p = 10;
    FuncPointArray(fooarray);
    printf("*p = %d\n",*p);// *p=10
    printf("p = %p\n",p); // 0x7ffeefbff5ec
    printf("&i = %p\n",&i); // 0x7ffeefbff5ec
    printf("i = %d\n",i); // i=10
    return 0;
}

void sum(int min,int max,int *ans)
{
    printf("ans");
    //ans = (min + max) //*(max - min + 1) / 2;
    return;
}

int FuncPointArray(int* array)
{
    printf("print array address = %p\n",array);
    printf("print array address = %d\n",array[2]);
    printf("\n");

    return 0;
}
