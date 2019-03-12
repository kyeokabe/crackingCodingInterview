//compute Nth Fibonnacci series using memoization

#include <iostream>
#include<stdio.h>
using namespace std;

int fibo(int N, int memo[]);

int main() {

    int N=43;
    int memo[N+1];
    for (int i=0;i<=N;i++)
        memo[i]=0;
    
    int foo=fibo(N,memo);
    cout <<N<<"th Fibonacci series = "<<foo<<endl;
    return 0;
}

int fibo(int N, int memo[]){
    if (N<0)
        return 0;
    if (N==1 || N==2){
        return 1;
    }
    ///* these are the lines that make a great speed difference!
    if (memo[N]!=0)
        return memo[N];
    //*/
    memo[N] = fibo(N-1, memo)+fibo(N-2, memo);
    return memo[N];
}
