class Solution {
public:
    int knightDialer(int N) {
        vector<int> f(10,0);
        vector<vector<int>> v(N,f);
        
        int MOD=pow(10,9)+7;
        
        for(int j=0;j<10;j++)
            v[0][j]=1;
        
        for(int i=1;i<N;i++){
            v[i][0]=(v[i-1][4]+v[i-1][6])%MOD;
            v[i][1]=(v[i-1][6]+v[i-1][8])%MOD;
            v[i][2]=(v[i-1][7]+v[i-1][9])%MOD;
            v[i][3]=(v[i-1][4]+v[i-1][8])%MOD;
            v[i][4]=((v[i-1][3]+v[i-1][9])%MOD+v[i-1][0])%MOD;
            
            v[i][6]=((v[i-1][1]+v[i-1][7])%MOD+v[i-1][0])%MOD;
            v[i][7]=(v[i-1][2]+v[i-1][6])%MOD;
            v[i][8]=(v[i-1][1]+v[i-1][3])%MOD;
            v[i][9]=(v[i-1][2]+v[i-1][4])%MOD;            
        }
        
        int ans=0;
        for(int j=0;j<10;j++)
            ans=(ans+v[v.size()-1][j])%MOD;
        
        return ans;
    }
};
