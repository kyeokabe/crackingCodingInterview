//1.7 Rotate Matrix Brute Force Solution

//Given an image represented by an NxN matrix, 
//where each pixel in the image is 4 bytes, 
//write a method to rotate the image by 90 degrees. 
//Can you do this in place?

//"in place" solution not complete
//assuming 90 deg clockwise rotation

#include <iostream>
#include<stdio.h>
using namespace std;

void printArray(float a[4][4]);
void CW90Rotate(float a[4][4]);

int main() {

    float a[4][4]={
        {7,1,1,2},
        {9,0,6,3},
        {8,1,9,2},
        {1,0,9,4}
    };

    printArray(a);
    cout << "\n";
    CW90Rotate(a);
    cout <<"\n";
    printArray(a);
    return 0;
}

void CW90Rotate(float a[4][4]){
    //create new template matrix w same size as a
    float b[4][4]={
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            b[j][3-i]=a[i][j];
 
    //why can't the bottom 3 lines be replaced by a=b?
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            a[i][j]=b[i][j];
}

void printArray(float a[4][4]){
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++)
            cout << a[i][j];
        cout << "\n";
    }
}
