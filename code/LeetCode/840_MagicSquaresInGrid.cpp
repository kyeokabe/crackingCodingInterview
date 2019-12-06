class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3||grid[0].size()<3)
            return 0;
        int ans=0;
        for(int r=0;r<grid.size()-2;r++){
            for(int c=0;c<grid[0].size()-2;c++){
                if(grid[r+1][c+1]!=5)
                    continue;
                
                if(grid[r][c]>9||grid[r][c]<1)
                    continue;
                if(grid[r+1][c]>9||grid[r+1][c]<1)
                    continue;
                if(grid[r+2][c]>9||grid[r+2][c]<1)
                    continue;
                if(grid[r][c+1]>9||grid[r][c+1]<1)
                    continue;
                //if(grid[r+1][c+1]>9||grid[r+1][c+1]<1)
                //    continue;
                if(grid[r+2][c+1]>9||grid[r+2][c+1]<1)
                    continue;
                if(grid[r][c+2]>9||grid[r][c+2]<1)
                    continue;
                if(grid[r+1][c+2]>9||grid[r+1][c+2]<1)
                    continue;
                if(grid[r+2][c+2]>9||grid[r+2][c+2]<1)
                    continue;
                
                vector<int> temp(9,0);
                temp[grid[r+0][c+0]-1]++;
                temp[grid[r+1][c+0]-1]++;
                temp[grid[r+2][c+0]-1]++;
                
                temp[grid[r+0][c+1]-1]++;
                temp[grid[r+1][c+1]-1]++;
                temp[grid[r+2][c+1]-1]++;
                
                temp[grid[r+0][c+2]-1]++;
                temp[grid[r+1][c+2]-1]++;
                temp[grid[r+2][c+2]-1]++;
                bool invalid_num=false;
                for(int i=0;i<9;i++)
                    if(temp[i]!=1)
                        invalid_num=true;
                
                if(invalid_num)
                    continue;
                
                if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=15)
                    continue;
                if(grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=15)
                    continue;
            
                if(grid[r][c]+grid[r][c+1]+grid[r][c+2]!=15)
                    continue;
                if(grid[r+1][c]+grid[r+1][c+1]+grid[r+1][c+2]!=15)
                    continue;
                if(grid[r+2][c]+grid[r+2][c+1]+grid[r+2][c+2]!=15)
                    continue;
                            
                if(grid[r][c]+grid[r+1][c]+grid[r+2][c]!=15)
                    continue;
                if(grid[r][c+1]+grid[r+1][c+1]+grid[r+2][c+1]!=15)
                    continue;
                if(grid[r][c+2]+grid[r+1][c+2]+grid[r+2][c+2]!=15)
                    continue;
                ans++;
            }
        }
        return ans;
    }
};
