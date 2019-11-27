class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]==1){
                    int temp=1;
                    grid[r][c]=0;
                    help(grid,r,c,temp,ans);
                }
            }
        }
        return ans;
    }
    
    void help(vector<vector<int>>& grid,int r,int c,int &temp,int &ans){
        if(temp>ans)
            ans=temp;
        if(r-1>=0&&grid[r-1][c]==1){
            grid[r-1][c]=0;
            temp++;
            help(grid,r-1,c,temp,ans);
        }
        if(r+1<grid.size()&&grid[r+1][c]==1){
            grid[r+1][c]=0;
            temp++;
            help(grid,r+1,c,temp,ans);
        }
        if(c-1>=0&&grid[r][c-1]==1){
            grid[r][c-1]=0;
            temp++;
            help(grid,r,c-1,temp,ans);
        }
        if(c+1<grid[0].size()&&grid[r][c+1]==1){
            grid[r][c+1]=0;
            temp++;
            help(grid,r,c+1,temp,ans);
        }
    }
    
};
