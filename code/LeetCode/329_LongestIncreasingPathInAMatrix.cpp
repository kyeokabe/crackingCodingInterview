class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        if(matrix.size()==0||matrix[0].size()==0)
            return ans;
        vector<int> v1(matrix[0].size(),0);
        vector<vector<int>> v(matrix.size(),v1);
        
        for(int r=0;r<matrix.size();r++)
            for(int c=0;c<matrix[0].size();c++)
                help(r,c,v,matrix,ans);
        return ans;
    }
    
    int help(int r, int c, vector<vector<int>> &v,vector<vector<int>> &m, int &ans){
        int up=1,down=1,left=1,right=1;
        
        if(r-1>=0){
            if(m[r-1][c]>m[r][c]&&v[r-1][c]!=0)
                up=v[r-1][c]+1;
            else if(m[r-1][c]<=m[r][c]){
                up=1;
            }
            else
                up=1+help(r-1,c,v,m,ans);
        }
        if(r+1<m.size()){
            if(m[r+1][c]>m[r][c]&&v[r+1][c]!=0)
                down=v[r+1][c]+1;
            else if(m[r+1][c]<=m[r][c]){
                down=1;
            }
            else
                down=1+help(r+1,c,v,m,ans);
        }
        if(c-1>=0){
            if(m[r][c-1]>m[r][c]&&v[r][c-1]!=0)
                left=v[r][c-1]+1;
            else if(m[r][c-1]<=m[r][c]){
                left=1;
            }
            else
                left=1+help(r,c-1,v,m,ans);
        }
        if(c+1<m[0].size()){
            if(m[r][c+1]>m[r][c]&&v[r][c+1]!=0)
                right=v[r][c+1]+1;
            else if(m[r][c+1]<=m[r][c]){
                right=1;
            }
            else
                right=1+help(r,c+1,v,m,ans); 
        }
        
        v[r][c]=max(up,max(down,max(right,left)));
        if(ans<v[r][c])
            ans=v[r][c];
        return v[r][c];
    }
};
