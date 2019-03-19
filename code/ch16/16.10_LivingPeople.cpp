// 16.10 Living People

/*
Given a list of people with their birth and death years, implement a method
to compute the year with the most number of people alive. You may assume that
all people were born between 1900 and 2000 (inclusive). If a person was alive
during any portion of that year, they should be included in that year's count.
 
Assuming array length given.

Important to think how to reorganize the array to a convenient format.
Not too difficult, but made a few small errors.
 */

#include <iostream>
#include <stdio.h>
using namespace std;

int mostAlive(int a[],int b[],int length);

int main(){
    
    int length=10;
    int birthYear[10]={1900,1904,1989,1905,1966,1927,1955,1992,1942,1972};
    int deathYear[10]={1903,1964,1998,1934,1974,1947,1965,1999,1982,1992};
    int answer=mostAlive(birthYear, deathYear,length);
    cout<<"answer: "<<answer<<endl;
    return 0;
}

int mostAlive(int a[],int b[], int length){

    int alive[101];
    int dead[101];
    int aliveInYear[101];
    
    for (int i=0;i<101;i++){
        alive[i]=0;
        dead[i]=0;
        aliveInYear[i]=0;
    }
    
    for (int i=0;i<length;i++){
        alive[a[i]-1900]++;
        dead[b[i]-1900]++;
    }
    int cumul_alive=0;
    int cumul_dead=0;
    
    for (int i=0;i<101;i++){
        cumul_alive+=alive[i];
        cumul_dead+=dead[i];
        aliveInYear[i]=cumul_alive-cumul_dead;
        cout<<"year: "<<1900+i<<", alive: "<<aliveInYear[i]<<endl;
    }
    
    int count=0;
    int index=0;
    
    for (int i=0;i<101;i++){
        if (aliveInYear[i]>count){
            count=aliveInYear[i];
            index=i;
        }
    }
    return index+1900;
}
