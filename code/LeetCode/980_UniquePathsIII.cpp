class Solution {
private:
    //row & col of ending square
    int R;
    int C;
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<int> starting;
        vector<int> ending;
        
        int num_0=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    starting.push_back(i);
                    starting.push_back(j);                    
                }
                if(grid[i][j]==2){
                    ending.push_back(i);
                    ending.push_back(j);                    
                }
                if(grid[i][j]==0){
                    num_0++;                   
                }
            }
        
        R=ending[0];
        C=ending[1];
        
        int ans=0;
        int r=starting[0];
        int c=starting[1];
        
        grid[r][c]=0;
        num_0++;
        
        help(grid,r,c,num_0,ans);
        return ans;
    }
    
    void help(vector<vector<int>>& grid, int r, int c, int num_0, int &ans){
        if(r==R&&c==C&&num_0==0){
            ans++;
            return;
        }
        
        if(r==R&&c==C&&num_0!=0)
            return;
        
        //go down
        if(r+1<grid.size()&&(grid[r+1][c]==0||grid[r+1][c]==2)){
            grid[r][c]=-1;
            help(grid,r+1,c,num_0-1,ans);
            grid[r][c]=0;
        }
        
        //go up
        if(r-1>=0&&(grid[r-1][c]==0||grid[r-1][c]==2)){
            grid[r][c]=-1;
            help(grid,r-1,c,num_0-1,ans);
            grid[r][c]=0;
        }
        
        //go right
        if(c+1<grid[0].size()&&(grid[r][c+1]==0||grid[r][c+1]==2)){
            grid[r][c]=-1;
            help(grid,r,c+1,num_0-1,ans);
            grid[r][c]=0;
        }
        
        //go left
        if(c-1>=0&&(grid[r][c-1]==0||grid[r][c-1]==2)){
            grid[r][c]=-1;
            help(grid,r,c-1,num_0-1,ans);
            grid[r][c]=0;
        }
    }
};
