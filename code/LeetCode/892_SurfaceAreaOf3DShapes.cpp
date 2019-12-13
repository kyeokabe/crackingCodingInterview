class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]!=0)
                    ans+=2;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                int temp=4*grid[r][c];
                if(r-1>=0)
                    temp-=min(grid[r-1][c],grid[r][c]);
                if(c-1>=0)
                    temp-=min(grid[r][c-1],grid[r][c]);
                if(r+1<grid.size())
                    temp-=min(grid[r+1][c],grid[r][c]);
                if(c+1<grid[0].size())
                    temp-=min(grid[r][c+1],grid[r][c]);
                ans+=temp;
            }
        }
        return ans;
    }
};
