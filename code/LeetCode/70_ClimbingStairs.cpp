/*
learned that memoization with vectors is 
seemingly noticably slower than
memoization with arrays
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n==0 || n==1)
            return 1;
        int foo[n+1];
        for (int i=0;i<=n;i++)
            foo[i]=0;
        foo[0]=1;
        foo[1]=1;
        return climbStairs(n-1,foo)+climbStairs(n-2,foo);
    }
    
        int climbStairs(int n, int foo[]) {
            if (foo[n]!=0)
                return foo[n];
            //if ((n==0) || (n==1))
            //    return 1;
            if (foo[n]==0)
                foo[n]=climbStairs(n-1,foo)+climbStairs(n-2,foo);
            return foo[n];
        }
};
