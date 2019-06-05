class Solution {
public:
    int climbStairs(int n) {
        vector<int> v;
        for(int i=0;i<n+1;i++)
            v.push_back(0);
        v[0]=1;
        v[1]=1;
        if(n<=1)
            return v[n];
        return help(n-1,v)+help(n-2,v);
    }
    
    int help(int n,vector<int> &v){
        if(v[n]==0)
            v[n]=help(n-1,v)+help(n-2,v);
        return v[n];
    }
};
