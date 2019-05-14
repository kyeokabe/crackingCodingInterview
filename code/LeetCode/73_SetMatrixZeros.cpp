class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //idea adapted from
        //https://leetcode.com/problems/set-matrix-zeroes/discuss/26014/Any-shorter-O(1)-space-solution
        //mzchen
        if(matrix.size()==1&&matrix[0].size()==0)
            return;
        
        bool row0=false;
        bool col0=false;
        
        for(int r=0;r<matrix.size();r++)
            if(matrix[r][0]==0)
                row0=true;
        
        for(int c=0;c<matrix[0].size();c++)
            if(matrix[0][c]==0)
                col0=true;
        
        if(matrix[0][0]!=0){
            for(int c=1;c<matrix[0].size();c++)
                if (matrix[0][c]==0){
                    matrix[0][0]=0;
                    break;
                }
            
            for(int r=1;r<matrix.size();r++)
                if(matrix[r][0]==0)
                    matrix[0][0]=0;
        }
        
        for(int c=1;c<matrix[0].size();c++)
            for(int r=1;r<matrix.size();r++){
                if(matrix[r][c]==0)
                    matrix[0][c]=0;
            }
        
        for(int r=1;r<matrix.size();r++)
            for(int c=1;c<matrix[0].size();c++){
                if(matrix[r][c]==0)
                    matrix[r][0]=0;
            }
        
        for(int c=1;c<matrix[0].size();c++)
            if(matrix[0][c]==0)
                for(int r=1;r<matrix.size();r++)
                    matrix[r][c]=0;
        
        for(int r=1;r<matrix.size();r++)
            if(matrix[r][0]==0)
                for(int c=1;c<matrix[0].size();c++)
                    matrix[r][c]=0;
        
        if(row0)
            for(int r=0;r<matrix.size();r++)
                matrix[r][0]=0;
        
        if(col0)
            for(int c=0;c<matrix[0].size();c++)
                matrix[0][c]=0;  
    }   
};
