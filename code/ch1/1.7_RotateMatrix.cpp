//1.7 Rotate Matrix Brute Force Solution & in place solution

//Given an image represented by an NxN matrix,
//where each pixel in the image is 4 bytes,
//write a method to rotate the image by 90 degrees.
//Can you do this in place?

//"in place" solution not complete ... complete 3/12/2019
//assuming 90 deg clockwise rotation

#include <iostream>
#include<stdio.h>
using namespace std;

const int MAX_ROWS=4;
const int MAX_COLS=4;

void printArray(float a[MAX_ROWS][MAX_COLS]);
void CW90Rotate(float a[MAX_ROWS][MAX_COLS]);

void CW90inPlace(float a[MAX_ROWS][MAX_COLS]);

int main() {
    float a[MAX_ROWS][MAX_COLS]={
        {7,1,1,2},
        {9,0,6,3},
        {8,1,9,2},
        {1,0,9,4}
    };
    
    //switch names a and b to toggle even vs odd matricies
    //also change MAX_ROWS & MAX_COLS appropriately
    float b[5][5]={
        {7,1,1,2,0},
        {9,0,6,3,9},
        {8,1,9,2,3},
        {1,0,9,4,5},
        {7,6,1,4,2},

    };
    
    cout <<"original matrix: \n\n";
    printArray(a);
    cout << "\n";
    
    /*
    CW90Rotate(a);
    cout <<"copy rotated matrix: \n\n";
    printArray(a);
    cout <<endl;
    */
    
    
    CW90inPlace(a);
    cout <<"in place copy rotated matrix: \n\n";
    printArray(a);
    cout <<endl;
    return 0;
}

void CW90Rotate(float a[MAX_ROWS][MAX_COLS]){
    //create new template matrix w same size as a
    float b[MAX_ROWS][MAX_COLS]={
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    
    for (int i=0;i<MAX_ROWS;i++)
        for (int j=0;j<MAX_COLS;j++)
            b[j][3-i]=a[i][j];
    
    //why can't the bottom 3 lines be replaced by a=b?
    for (int i=0;i<MAX_ROWS;i++)
        for (int j=0;j<MAX_COLS;j++)
            a[i][j]=b[i][j];
}

void printArray(float a[MAX_ROWS][MAX_ROWS]){
    for (int i=0;i<MAX_ROWS;i++){
        for (int j=0;j<MAX_COLS;j++)
            cout << a[i][j];
        cout << "\n";
    }
}

void CCW90inPlace(float a[MAX_ROWS][MAX_COLS]){
    
    if (MAX_ROWS%2==0){ //if N is even
        for (int i=0;i<=MAX_ROWS/2-1;i++)
            for (int j=0;j<=MAX_ROWS/2-1;j++)
            {
                int temp1, temp2, temp3, temp4;
                temp1=a[i][j];
                temp2=a[MAX_ROWS-1-j][i];
                temp3=a[MAX_ROWS-1-i][MAX_ROWS-1-j];
                temp4=a[j][MAX_ROWS-1-i];
                a[MAX_ROWS-1-j][i]=temp1;
                a[MAX_ROWS-1-i][MAX_ROWS-1-j]=temp2;
                a[j][MAX_ROWS-1-i]=temp3;
                a[i][j]=temp4;
                //cout<<"foo"<<endl;
            }
    }
    
    if (MAX_ROWS%2==1){ //if N is even
        for (int i=0;i<=MAX_ROWS/2;i++)
            for (int j=0;j<=MAX_ROWS/2-1;j++)
            {
                int temp1, temp2, temp3, temp4;
                temp1=a[i][j];
                temp2=a[MAX_ROWS-1-j][i];
                temp3=a[MAX_ROWS-1-i][MAX_ROWS-1-j];
                temp4=a[j][MAX_ROWS-1-i];
                a[MAX_ROWS-1-j][i]=temp1;
                cout<<"temp1 = "<<temp1<<endl;
                cout<<"MAX_ROWS-1-j = "<<MAX_ROWS-1-j<<endl;
                cout<<"i = "<<i<<endl;
                cout<<"a[MAX_ROWS-1-j][i] = "<<a[MAX_ROWS-1-j][i]<<endl;

                a[MAX_ROWS-1-i][MAX_ROWS-1-j]=temp2;
                a[j][MAX_ROWS-1-i]=temp3;
                a[i][j]=temp4;
                //cout<<"foo2"<<endl;
            }
    }

}

void CW90inPlace(float a[MAX_ROWS][MAX_COLS]){
    
    if (MAX_ROWS%2==0){ //if N is even
        for (int i=0;i<=MAX_ROWS/2-1;i++)
            for (int j=0;j<=MAX_ROWS/2-1;j++)
            {
                int temp1, temp2, temp3, temp4;
                temp1=a[j][i];
                temp2=a[i][MAX_ROWS-1-j];
                temp3=a[MAX_ROWS-1-j][MAX_ROWS-1-i];
                temp4=a[MAX_ROWS-1-i][j];
                a[i][MAX_ROWS-1-j]=temp1;
                a[MAX_ROWS-1-j][MAX_ROWS-1-i]=temp2;
                a[MAX_ROWS-1-i][j]=temp3;
                a[j][i]=temp4;
                //cout<<"foo"<<endl;
            }
    }
    
    if (MAX_ROWS%2==1){ //if N is even
        for (int i=0;i<=MAX_ROWS/2;i++)
            for (int j=0;j<=MAX_ROWS/2-1;j++)
            {
                int temp1, temp2, temp3, temp4;
                temp1=a[j][i];
                temp2=a[i][MAX_ROWS-1-j];
                temp3=a[MAX_ROWS-1-j][MAX_ROWS-1-i];
                temp4=a[MAX_ROWS-1-i][j];
                a[i][MAX_ROWS-1-j]=temp1;
                
                a[MAX_ROWS-1-j][MAX_ROWS-1-i]=temp2;
                a[MAX_ROWS-1-i][j]=temp3;
                a[j][i]=temp4;
                //cout<<"foo2"<<endl;
            }
    }
    
}
