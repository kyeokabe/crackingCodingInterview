class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size()==0||matrix[0].size()==0)
            return ans;
        
        vector<int> f(matrix[0].size(),1);
        vector<vector<int>> v(matrix.size(),f);
        
        int r=0;
        int c=0;
        int count=matrix.size()*matrix[0].size();
        int direction=0;
        
        while(count>0){
            ans.push_back(matrix[r][c]);
            v[r][c]=0;
            count--;
            //go right
            if(direction%4==0){
                if(c+1<matrix[0].size()&&v[r][c+1]==1)
                    c++;
                else{
                    direction++;
                    r++;
                }
            }
            else if(direction%4==1){
                if(r+1<matrix.size()&&v[r+1][c]==1)
                    r++;
                else{
                    direction++;
                    c--;
                }
            }
            else if(direction%4==2){
                if(c-1>=0&&v[r][c-1]==1)
                    c--;
                else{
                    direction++;
                    r--;
                }
            }
            else{
                if(r-1>=0&&v[r-1][c]==1)
                    r--;
                else{
                    direction++;
                    c++;
                }
            }
        }
        return ans;
    }
};
