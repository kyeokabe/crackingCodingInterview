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
