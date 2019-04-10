class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ROW=grid.size();
        int COL=grid[0].size();
        int t=max(grid[ROW-1][COL-1],grid[0][0]);//min time it will take
        grid[0][0]=-1;
        //cout<<"t = "<<t<<endl;
        int r=0;//current row coordinate
        int c=0;//current col coordinate
        bool pathclear=false;
        vector<vector<int>> gridCopy2;
        gridCopy2=grid;
        helper(gridCopy2,t,r,c,pathclear);//get initial result
        while(!pathclear){
            vector<vector<int>> gridCopy;
            gridCopy=grid;
            t++;//keep evaluating incrementing time
            helper(gridCopy,t,r,c,pathclear);
        }
        return t;
    }
    
    void helper(vector<vector<int>> &grid,int t,int r,int c,bool &pathclear){
        //cout<<"r = "<<r<<", c = "<<c<<", grid = "<<grid[r][c]<<endl;
        int ROW=grid.size();
        int COL=grid[0].size();
        if (r==ROW-1&&c==COL-1){
            pathclear=true;
            return;
        }
        if(r+1<ROW)
            if(grid[r+1][c]!=-1&&grid[r+1][c]<=t){
                grid[r+1][c]=-1;
                helper(grid,t,r+1,c,pathclear);
            }
        if(c+1<COL)
            if(grid[r][c+1]!=-1&&grid[r][c+1]<=t){
                grid[r][c+1]=-1;
                helper(grid,t,r,c+1,pathclear);
            }
        if(c-1>=0)
            if(grid[r][c-1]!=-1&&grid[r][c-1]<=t){
                grid[r][c-1]=-1;
                helper(grid,t,r,c-1,pathclear);
            }
        if(r-1>=0)
            if(grid[r-1][c]!=-1&&grid[r-1][c]<=t){
                grid[r-1][c]=-1;
                helper(grid,t,r-1,c,pathclear);
            }
    }
};
