class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> foo(d+1,0);
        vector<vector<int>> v(target+1,foo);
        
        int MOD=pow(10,9)+7;
        
        //v[i][j]   ... number of ways to get sum i with j die
        
        for(int i=1;i<=f;i++)
            if(i<=target)
                v[i][1]=1;
        
        for(int j=2;j<=d;j++){
            for(int i=0;i<=target;i++){
                for(int k=1;k<=f;k++){
                    if(i+k<=target)
                        v[i+k][j]=(v[i+k][j]+v[i][j-1])%MOD;
                }
            }
        }
        
        return v[target][d];
    }
};
