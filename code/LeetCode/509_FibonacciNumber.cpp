class Solution {
public:
    int fib(int N) {
        unordered_map<int,int> m;
        m[0]=0;
        m[1]=1;
        return fib2(N,m);
    }
    
    int fib2(int N, unordered_map<int,int> &m){
        auto it=m.find(N);
        if(it!=m.end())
            return it->second;
        
        //else
        m[N]=fib2(N-1,m)+fib2(N-2,m);
        return m[N];
    }
};
