/*
basic idea is to iterate through A vector and update A
by += using previous row numbers.
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        for (int r=1;r<A.size();r++){
            for (int c=0;c<A.size();c++){
                int temp=A[r-1][c];
                if(c-1>=0)
                    temp=min(temp,A[r-1][c-1]);
                if(c+1<=A.size()-1)
                    temp=min(temp,A[r-1][c+1]);
                A[r][c]+=temp;
            }
        }
        int ans=A[A.size()-1][A.size()-1];
        for (int c=0;c<A.size();c++)
            if (A[A.size()-1][c]<ans)
                ans=A[A.size()-1][c];
        return ans;
    }
};
