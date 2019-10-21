class Solution {
public:
    vector<vector<int>> generateMatrix(int n){
        vector<int> f(n,0);
        vector<vector<int>> v(n,f);
        
        int r=0;
        int c=0;
        int count=n*n;
        int direction=0;
        
        while(count>0){
            v[r][c]=n*n-count+1;
            count--;
            //go right
            if(direction%4==0){
                if(c+1<v[0].size()&&v[r][c+1]==0)
                    c++;
                else{
                    direction++;
                    r++;
                }
            }
            else if(direction%4==1){
                if(r+1<v.size()&&v[r+1][c]==0)
                    r++;
                else{
                    direction++;
                    c--;
                }
            }
            else if(direction%4==2){
                if(c-1>=0&&v[r][c-1]==0)
                    c--;
                else{
                    direction++;
                    r--;
                }
            }
            else{
                if(r-1>=0&&v[r-1][c]==0)
                    r--;
                else{
                    direction++;
                    c++;
                }
            }
        }
        return v;
    }
};
