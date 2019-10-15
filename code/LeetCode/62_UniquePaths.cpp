class Solution {
public:
    int uniquePaths(int m, int n) {
        int x=1,y=1;
        map<vector<int>,int> MP;
        vector<int> temp={0,0};
        MP[temp]=1;

        return help(x,y,m,n,MP);
    }
    
    int help(int x, int y, int m, int n, map<vector<int>,int> &MP){
        vector<int> temp={m-x,n-y};
        auto it=MP.find(temp);
        if(it!=MP.end())
            return it->second;

        if(x<m&&y==n){
            int k=help(x+1,y,m,n,MP);
            MP[temp]=k;
            return k;
        }
        if(x==m&&y<n){
            int k=help(x,y+1,m,n,MP);
            MP[temp]=k;
            return k;
        }
        
        int k=help(x+1,y,m,n,MP)+help(x,y+1,m,n,MP);
        MP[temp]=k;
        return k;
    }
};

/*
//added new solution on 10/14/2019
//need to be careful of overflow issues

//review permutations with duplicates
//https://www.geisya.or.jp/~mwm48961/kou3/onajimono1.htm
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n>m)
            swap(m,n);
        
        m--;//m represents number of right (or down) moves necessary to reach target
        n--;//n represents number of right (or down) moves necessary to reach target
        
        //m>=n
        //unsigned long long seems to return incorrect division
        unsigned long num=1;
        unsigned long den=1;
        
        while(n>0){
            num=num*(m+n);
            den=den*n;
            n--;
        }
        return int(num/den);
        //22 15 ish is max
    }
};

*/
