//very basics of pointers

#include <stdio.h>

int main(void)
{
    int *p;
    int i=5;
    p = &i;
    *p = 10;
    printf("*p = %d\n",*p);// *p=10
    printf("p = %p\n",p); // 0x7ffeefbff5ec
    printf("&i = %p\n",&i); // 0x7ffeefbff5ec
    printf("i = %d\n",i); // i=10
    return 0;
}
