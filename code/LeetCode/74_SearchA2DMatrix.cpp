class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r_size=matrix.size();//row size
        if (r_size==0)
            return false;
        int c_size=matrix[0].size();//col size
        
        if (r_size==0 || c_size==0)
            return false;
        
        int r=0;
        int c=0;
        
        for (int i=0;i<r_size;i++)
            for (int j=0;j<c_size;j++)
                if (matrix[i][j]==target)
                    return true;
        
        return false;
    }
    
    
};
