class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int ans=0;
        
        vector<int> foo(B.size(),0);
        vector<vector<int>> v(A.size(),foo);
        
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                if(A[i]==B[j]){
                    v[i][j]=1;
                }
            }
        }
        
        for(int i=A.size()-2;i>=0;i--){
            v[i][B.size()-1]=max(v[i][B.size()-1],v[i+1][B.size()-1]);
            if(v[i][B.size()-1]>ans)
                ans=v[i][B.size()-1];
        }

        for(int j=B.size()-2;j>=0;j--){
            v[A.size()-1][j]=max(v[A.size()-1][j],v[A.size()-1][j+1]);
            if(v[A.size()-1][j]>ans)
                ans=v[A.size()-1][j];
        }
        
        for(int i=A.size()-2;i>=0;i--){
            for(int j=B.size()-2;j>=0;j--){
                v[i][j]=max(max(v[i+1][j],v[i][j+1]),v[i+1][j+1]+v[i][j]);
                if(v[i][j]>ans)
                    ans=v[i][j];
            }
        }
        
        return ans;
    }
};
