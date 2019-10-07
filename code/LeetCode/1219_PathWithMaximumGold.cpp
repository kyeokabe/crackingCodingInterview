class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        for(int r=0;r<grid.size();r++)
            for(int c=0;c<grid[0].size();c++){
                int sum=0;
                help(grid,r,c,sum,ans);
            }
        return ans;
    }
    
    void help(vector<vector<int>>& grid, int r, int c, int sum, int &ans){
        if(r>=0&&r<grid.size()&&c>=0&&c<grid[0].size()&&grid[r][c]>0){
            
            sum+=grid[r][c];
            if(ans<sum)
                ans=sum;
            
            int temp=grid[r][c];
            grid[r][c]=0;
            
            help(grid,r+1,c,sum,ans);
            help(grid,r-1,c,sum,ans);
            help(grid,r,c+1,sum,ans);
            help(grid,r,c-1,sum,ans);
            
            //this line is very tricky to come up with!
            //this keeps space O(m*n)
            //alternatively could pass modified array 
            //by non-ref, but very memory expensive!
            grid[r][c]=temp;
        }
        else{
            return;
        }   
    }
};
