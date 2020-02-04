class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        if(grid.size()==0||grid[0].size()==0)
            return 0;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]==1){
                    if(r-1<0||grid[r-1][c]==0)
                        ans++;
                    if(r+1>=grid.size()||grid[r+1][c]==0)
                        ans++;
                    if(c-1<0||grid[r][c-1]==0)
                        ans++;
                    if(c+1>=grid[0].size()||grid[r][c+1]==0)
                        ans++;
                }
            }
        }
        return ans;
    }
};
