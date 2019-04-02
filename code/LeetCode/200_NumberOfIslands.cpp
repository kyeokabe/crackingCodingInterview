class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size()==0)
            return 0;
        if (grid.size()==1)
            if (grid[0].size()==0)
                return 0;
        int r=grid.size();
        int c=grid[0].size();
        int counter=0;
        
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++){
                if (grid[i][j]=='1'){
                    helper(grid,i,j);
                    counter++;
                }
            }

        return counter;
    }
    
    void helper(vector<vector<char>>& grid, int i, int j){
        int r=grid.size();
        int c=grid[0].size();
        
        if (grid[i][j]=='0')
            return;
        else{
            grid[i][j]='0';
            if (i>=0 && i<=r-1 && j>=0 && j<=c-1){
                if (j>0)
                    helper(grid,i,j-1);
                if (j<c-1)
                    helper(grid,i,j+1);
                if (i>0)
                    helper(grid,i-1,j);
                if (i<r-1)
                    helper(grid,i+1,j);
            }
        }
    }
};
