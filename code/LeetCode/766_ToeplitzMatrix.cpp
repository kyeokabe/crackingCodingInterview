class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        
        int m=max(r,c);
        
        #check row diagonals
        for (int i=0;i<m;i++)
            for (int j=0; j<m;j++)
                if (i+j+1<=r-1&&i+1<=c-1)
                    if (matrix[i+j][i]!=matrix[i+j+1][i+1])
                        return false;
        #check col diagonals
        for (int i=0;i<m;i++)
            for (int j=0; j<m;j++)
                if (i+1<=r-1&&i+j+1<=c-1)
                    if (matrix[i][i+j]!=matrix[i+1][i+j+1])
                        return false;        
        return true;
    }
};
