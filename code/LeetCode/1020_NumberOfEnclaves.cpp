class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        //https://leetcode.com/problems/number-of-enclaves/discuss/265555/C%2B%2B-with-picture-DFS-and-BFS
        //adapted from votrubac
        for (int i=0;i<A[0].size();i++){
            if(A[0][i]==1){
                A[0][i]=0;
                help2(A,0,i);
            }
            if(A[A.size()-1][i]==1){
                A[A.size()-1][i]=0;
                help2(A,A.size()-1,i);
            }
        }
        for (int i=0;i<A.size();i++){
            if(A[i][0]==1){
                A[i][0]=0;
                help2(A,i,0);
            }
            if(A[i][A[0].size()-1]==1){
                A[i][A[0].size()-1]=0;
                help2(A,i,A[0].size()-1);
            }
        }

        int ans=0;
        for(int i=0;i<A[0].size();i++)
            for(int j=0;j<A.size();j++)
                if (A[j][i]==1)
                    ans=ans+1;
        return ans;
    }
    
    void help2(vector<vector<int>> &A, int m, int n){
        int N=A[0].size()-1;//A[M][N]
        int M=A.size()-1;//A[M][N]
        if(m>0)
            if(A[m-1][n]==1){
                A[m-1][n]=0;
                help2(A,m-1,n);
            }

        if(m<M)
            if(A[m+1][n]==1){
                A[m+1][n]=0;
                help2(A,m+1,n);
            }
        
        if(n>0)
            if(A[m][n-1]==1){
                A[m][n-1]=0;
                help2(A,m,n-1);
            }

        if(n<N)
            if(A[m][n+1]==1){
                A[m][n+1]=0;
                help2(A,m,n+1);
            }
    }
};
