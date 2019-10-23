class Solution {
public:
    int numWays(int n, int k) {
        if(n==0)
            return 0;
        if(n==1)
            return k;
        if(n==2)
            return k*k;
        
        vector<int> v(n,0);
        v[0]=k;
        v[1]=k*k;
        
        for(int i=2;i<n;i++)
            v[i]=v[i-1]*(k-1)+v[i-2]*(k-1);
        
        return v[n-1];
    }
};
