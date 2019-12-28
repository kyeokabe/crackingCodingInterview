class Solution {
public:
    int integerBreak(int n) {
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        if(n==4)
            return 4;
        
        int three=0;
        while(n>4){
            n-=3;
            three++;
        }
        int ans=pow(3,three);
        ans*=n;
        return ans;
        
        /*
        unordered_map<int,int> m;
        m[2]=1;
        m[3]=2;
        m[4]=4;
        m[5]=6;
        m[6]=9;
        int a=n/2;
        int b=n-a; 
        return help(a,m)*help(b,m);
        */
    }
    
    int help(int &a, unordered_map<int,int> &m){
        if(m.find(a)!=m.end())
            return m[a];
        else{
            int n1=a/2;
            int n2=a-n1;
            if(m.find(n1)==m.end())
                help(n1,m);
            if(m.find(n2)==m.end())
                help(n2,m);
            m[a]=n1*n2;
            return m[a];
        }
    }
    
};
