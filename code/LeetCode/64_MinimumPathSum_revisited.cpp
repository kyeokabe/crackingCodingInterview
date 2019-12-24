class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(c!=0&&r!=0)
                    grid[r][c]+=min(grid[r-1][c],grid[r][c-1]);
                else if(c!=0&&r==0)
                    grid[r][c]+=grid[r][c-1];
                else if(r!=0&&c==0)
                    grid[r][c]+=grid[r-1][c];
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
