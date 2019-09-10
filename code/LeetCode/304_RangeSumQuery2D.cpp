//adapted from haoel in discussion
//https://leetcode.com/problems/range-sum-query-2d-immutable/discuss/75350/Clean-C%2B%2B-Solution-and-Explaination-O(mn)-space-with-O(1)-time

class NumMatrix {

private:
    vector<vector<int>> v;
    int rowSize,colSize;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        v=matrix;
        rowSize=v.size();
        colSize=(rowSize>0)? v[0].size():0;
        
        if(colSize>0){
            for(int i=1;i<v.size();i++)
                v[i][0]+=v[i-1][0];
            for(int j=1;j<v[0].size();j++)
                v[0][j]+=v[0][j-1];
                
            for(int i=1;i<v.size();i++)
                for(int j=1;j<v[0].size();j++)
                    v[i][j]=v[i-1][j]+v[i][j-1]+matrix[i][j]-v[i-1][j-1];
        }      
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(rowSize==0||colSize==0)
            return 0;
        int sum=v[row2][col2];
        if(row1>0)
            sum-=v[row1-1][col2];
        if(col1>0)
            sum-=v[row2][col1-1];
        if(row1>0&&col1>0)
            sum+=v[row1-1][col1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
