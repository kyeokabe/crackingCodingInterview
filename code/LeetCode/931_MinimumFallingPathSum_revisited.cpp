class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int>> B=A;
        for(int i=1;i<B.size();i++){
            for(int j=0;j<B[0].size();j++){
                int a,c;
                int b=B[i-1][j];

                j-1>=0?a=B[i-1][j-1]:a=INT_MAX;
                j+1<B[0].size()?c=B[i-1][j+1]:c=INT_MAX;
                
                B[i][j]+=min(a,min(b,c));
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<B[0].size();j++)
            if(B[B.size()-1][j]<ans)
                ans=B[B.size()-1][j];
        return ans;
    }
};
