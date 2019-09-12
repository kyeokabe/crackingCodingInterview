//solved this simple case problem using step by step method recommended from below
//this covers both memoization (top-down ... recursion) and dynamic programming (bottom-up ... iterative)
//https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.

/*

******************************************
**Step 1. Figure out recursive relation.**
******************************************

F(n)=F(n-1)+F(n-2) ... (for n>1)

********************************
**Step 2. Recursive (top-down)**
********************************

//O(1) memory
//O(2^N) time

class Solution {
public:
    int fib(int N) {
        if (N==0)
            return 0;
        if (N==1)
            return 1;
        
        return fib(N-1)+fib(N-2);
    }
};

*******************************************************
**Step 3. Recursive (Memoization ... i.e., top-down).**
*******************************************************

//O(N) memory
//O(N) time

class Solution {
public:
    int fib(int N) {
        if (N<=1)
            return N;
        
        //v[i] stores Fib(i) answer
        //store INT_MIN if Fib(i) has not been calculated yet
        vector<int> v(N+1,INT_MIN);
        v[0]=0;
        v[1]=1;
        
        return fib_memo(N,v);
    }
    
    int fib_memo(int i, vector<int> &v){
        //use memo to return F(i) if previously calculated
        if(v[i]!=INT_MIN)
            return v[i];
        //otherwise, compute v[i] and return it
        else{
            v[i]=fib_memo(i-1,v)+fib_memo(i-2,v);
            return v[i];
        }
    }
};

***************************************************************
**Step 4. Iterative (Dynamic Programming ... i.e., bottom-up)**
***************************************************************

//O(N) memory
//O(N) time

class Solution {
public:
    int fib(int N) {
        if (N<=1)
            return N;
        
        vector<int> v(N+1,0);
        v[0]=0;
        v[1]=1;
        
        for(int i=2;i<=N;i++)
            v[i]=v[i-1]+v[i-2];

        return v[N];
    }
};

*****************************************************
**Step 5. Iterative with constant space (bottom-up)**
*****************************************************

//O(1) memory
//O(N) time

class Solution {
public:
    int fib(int N) {
        if (N<=1)
            return N;
        
        int num_small=0;
        int num_big=1;
        int n=0;
        
        for(int i=0;i<N-1;i++){
            n=num_small+num_big;
            num_small=num_big;
            num_big=n;
        }
        return n;
    }
};

*/
