// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> f(n,INT_MIN);
        vector<vector<int>> v(n,f);
        
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                v[i][j]=knows(i,j);
                if(v[i][j]==0)
                    break;
                if(i==n-1){
                    if(check(j,v,n))
                        return j;
                    else
                        return -1;
                }
            }
        }
        return -1;
    }
    
    bool check(int j, vector<vector<int>> &v,int n){
        for(int i=0;i<n;i++){
            if(v[j][i]==INT_MIN){
                v[j][i]=knows(j,i);
            }
            if(i!=j&&v[j][i]==1)
                return false;
        }
        return true;
    }
};
