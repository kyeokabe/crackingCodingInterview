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
        {9,0,6,3},
        {8,1,9,2}
    };
    
    printArray(a);
    cout<<"\n";
    checkArray(a);
    printArray(a);
    return 0;
}

void checkArray(float a[3][4]){
    //make a copy of a
    float b[3][4]={
        {7,1,1,2},
        {9,0,6,3},
        {8,1,9,8}
    };
    
    for (int i=0;i<3;i++)
        for (int j=0;j<4;j++)
            if (b[i][j]==0)
            {
                cout <<"foo \n";
                for (int m=0;m<3;m++)
                    for (int n=0;n<4;n++)
                        if ((m==i)||(n==j)){
                            cout<<"m,n= "<<m<<n<<"\n";
                            a[m][n]=0;
                        }
            }
    //a[2][2]=0;
    cout<<"\n";
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
