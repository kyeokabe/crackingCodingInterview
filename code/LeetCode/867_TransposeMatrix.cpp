class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        
        int r=A[0].size();//example will be 3// r is row of transposed matrix
        int c=A.size();//example will be 2// c is column of transposed matrix
        
        vector<int> foo;
        vector<vector<int>> ans;
        
        //want row x col = 2 x 3
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                foo.push_back(A[j][i]);
            ans.push_back(foo);
            foo={};
        }
        return ans;
    }
};
