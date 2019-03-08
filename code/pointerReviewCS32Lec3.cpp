//pointer review from CS32 Lec 3 ... take note on "very confusing" example

#include <iostream>
#include<stdio.h>
using namespace std;

void basicPointer(int* y1){
    *y1=2;
}

//passing by reference
void veryConfusiong(int &y2){
    y2=4;
}

//sending address to function
void swap(int *a,int *b){
    //int* c; //these two lines are incorrect because
    //*c=*a;  // c has uninitialized address stored
    
    int c;
    c=*a;
    *a=*b;
    *b=c;
}

//passing an array
void printData(int array[])
{
    cout<<"first  element = "<<array[0]<<"\n";
    cout<<"second element = "<<array[1]<<"\n";
    cout<<"\n";
}

struct Nerd
{
    int numZits;
    int hoursOfStarCraft;
};

//swapping variables by passing by reference
void ref1(int &x11, int &x12)
{
    int temp;
    temp=x11;
    x11=x12;
    x12=temp;
    cout<<"\n";
    cout<<"x11... = "<<x11<<"\n";
    cout<<"x12... = "<<x12<<"\n";
}

int main (){
    int x1=1;
    int x2=3;
    
    int a=5,b=6;
    
    swap(&a, &b);
    cout<<"a = "<<a<<"\n";
    cout<<"b = "<<b<<"\n";
    cout<<"\n";
    cout<<"Basic pointer example: x1 (before) = "<<x1<<"\n";
    
    basicPointer(&x1);
    cout<<"Basic pointer example: x1 (after) = "<<x1<<"\n";
    cout<<"\n";
    
    //note x2 being passed "raw"
    cout<<"Very confusing example: x2 (before) = "<<x2<<"\n";
    veryConfusiong(x2);
    cout<<"Very confusing example: x2 (after) = "<<x2<<"\n";
    cout<<"\n";
    
    //arrays
    int nums[3]={10,11,12};
    int *ptr=nums;
    
    cout <<"ptr[2]   = "<<ptr[2]<<"\n";
    cout <<"*ptr     = "<<*ptr<<"\n";
    cout <<"*(ptr+2) = "<<*(ptr+2)<<"\n";
    cout<<"\n";
    
    printData(nums);
    printData(&nums[1]);
    printData(nums+1);

    cout<<"\n";

    Nerd carey;
    Nerd *pointer;
    
    pointer = &carey;
    
    //need () to compile!
    (*pointer).numZits=140;
    pointer->hoursOfStarCraft=42;
    
    int x11=11,x12=12;
    ref1(x11,x12);
    
    cout<<"x11 = "<<x11<<"\n";
    cout<<"x12 = "<<x12<<"\n";

    /*dynamic memory allocation*/
    //step 1: define pointer
    int *array5;
    //step 2: assign pointer var. to new array (or int, class, etc.)
    array5 = new int[5];
    //step 3: use pointer variable as regular veriable ...
    array5[0]=4;
    array5[1]=0;
    array5[2]=8;
    array5[3]=9;

    cout<<"\n";
    cout << array5[2] << "\n";
    cout << "\n";
    //step 4: delete pointer variable
    delete [] array5;
    return 0;
}
