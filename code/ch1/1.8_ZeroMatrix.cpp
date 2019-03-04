//1.8 Zero Matrix
//write an algorithm such that if an element in an MxN matrix is 0,
//its entire row and column are set to 0

/*
  easy, no need to repeat
 */

#include <iostream>
#include<stdio.h>
using namespace std;

void checkArray(float a[3][4]);
void set0(float a[3][4]);
void printArray(float a[3][4]);

int main() {
    
    float a[3][4]={
        {7,1,1,2},
        {5,1,6,3},
        {8,1,9,2},
    };
    checkArray(a);
    printArray(a);
    return 0;
}

void checkArray(float a[3][4]){
    for (int i=0;i<3;i++)
        for (int j=0;j<4;j++)
            if (a[i][j]==0)
                set0(a);
}

void set0(float a[3][4]){
    for (int i=0;i<3;i++)
        for (int j=0;j<4;j++)
            a[i][j]=0;
}

void printArray(float a[3][4]){
    for (int i=0;i<3;i++){
        for (int j=0;j<4;j++)
            cout << a[i][j];
        cout << "\n";
    }
}
