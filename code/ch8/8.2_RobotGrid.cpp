//8.2
//write a recursive function that finds a path on a grid

/*
 still has bugs
 */

#include <iostream>
#include<stdio.h>
using namespace std;

bool FindPaths(int x, int y, int a[3][4]);
void print_2D_array(int a[3][4]);

int main() {
    int a[3][4]={
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    //int count=0;
    //int foo[]={};
    bool c=false;
    c=FindPaths(0,0,a);
    if (c==true)
      printf ("Answer is true\n");
    if (c==false)
      printf ("Answer is false\n");
    return 0;
}

void print_2D_array(int a[3][4]){
    for (int i=0;i<3;i++){
        for (int j=0;j<4;j++){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
}


bool FindPaths(int r, int c, int a[3][4]){
    if ((r==2) && (c==3))
        return true;
    //cout<< "array "<<"("<<x<<","<<y<<") = "<<a[x][y] <<"\n";

    
    if (a[r][c]!=1){
        a[r][c]=1;
        cout<<"r,c="<<r<<","<<c<<"\n";
        print_2D_array(a);
        cout<<"\n";
        if ((r>0)&&(a[r-1][c]==0))
            FindPaths(r-1,c,a);
        if ((r<2)&&(a[r+1][c]==0))
            FindPaths(r+1,c,a);
        if ((c>0)&&(a[r][c-1]==0))
            FindPaths(r,c-1,a);
        if ((c<3)&&(a[r][c+1]==0)){
            FindPaths(r,c+1,a);
        }
    }
    return false;
}
