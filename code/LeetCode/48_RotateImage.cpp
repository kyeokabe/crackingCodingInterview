class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //adapted from shichaotan
        //https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
        
        //swaps up and down
        for(int c=0;c<matrix[0].size();c++)
            for(int r=0;r<matrix.size()/2;r++){
                int temp=matrix[matrix.size()-1-r][c];
                matrix[matrix.size()-1-r][c]=matrix[r][c];
                matrix[r][c]=temp;
            }
        /*
        for(int r=0;r<matrix.size();r++)
            for(int c=0;c<matrix[0].size();c++)
                cout<<matrix[r][c]<<endl;
        */    
        //diagonal swap
        for(int r=0;r<matrix.size();r++)
            for(int c=0;c<r;c++){
                int temp=matrix[c][r];
                matrix[c][r]=matrix[r][c];
                matrix[r][c]=temp;
            }
    }
};
