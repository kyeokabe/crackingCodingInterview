class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1||n==2)
            return 1;
        vector<int> v(n+1,0);
        v[1]=1;
        v[2]=1;
        return help(n,v);
    }
    
    int help(int n,vector<int> &v){
        if (n==0)
            return 0;
        else if(v[n]!=0)
            return v[n];
        else{
            v[n]=help(n-3,v)+help(n-2,v)+help(n-1,v);
            return v[n];
        }
    }
};
