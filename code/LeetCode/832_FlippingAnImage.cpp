class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> B=A;
        for (int i=0;i<A.size();i++)
            for (int j=0;j<A[0].size();j++)
                B[i][A[0].size()-1-j]=(!A[i][j]);
        return B;
    }
};
