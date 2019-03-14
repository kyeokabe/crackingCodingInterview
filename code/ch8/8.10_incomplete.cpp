//8.10 Paint Fill

/*
 
 */

#include <iostream>
#include<stdio.h>
using namespace std;

void paintFill(int image[5][5], int x, int y);
void print_2D_array(int a[5][5]);

int main() {
    int image[5][5]={
        {4,4,4,4,4},
        {4,4,4,4,4},
        {4,4,4,4,4},
        {4,4,4,4,4},
        {4,4,4,4,4}
    };
    
    print_2D_array(image);
    cout<<"\n";
    int x=3, y=3;
    paintFill(image,x,y);
    print_2D_array(image);
    cout<<"\n";
    return 0;
}

void paintFill(int image[5][5], int x, int y){

}

void print_2D_array(int a[5][5]){
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
}
