class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        for(int m=0;m<b.size();m++)
            for(int n=0;n<b[0].size();n++){
                int sum=0;
                //need to add exceptions
                if(m-1>=0&&n-1>=0)
                    sum+=b[m-1][n-1]%10;
                if(m-1>=0)
                    sum+=b[m-1][n+0]%10;
                if(m-1>=0&&n+1<=b[0].size()-1)
                    sum+=b[m-1][n+1]%10;
                if(n-1>=0)
                    sum+=b[m+0][n-1]%10;
                if(n+1<=b[0].size()-1)                
                    sum+=b[m+0][n+1]%10;
                if(m+1<=b.size()-1&&n-1>=0)
                    sum+=b[m+1][n-1]%10;
                if(m+1<=b.size()-1)
                    sum+=b[m+1][n+0]%10;
                if(m+1<=b.size()-1&&n+1<=b[0].size()-1)
                    sum+=b[m+1][n+1]%10;
                
                b[m][n]=10*sum+b[m][n];
            }
        
        for(int m=0;m<b.size();m++)
            for(int n=0;n<b[0].size();n++){
                if(b[m][n]<19)
                    b[m][n]=0;
                else if(b[m][n]==21||b[m][n]==31)
                    b[m][n]=1;
                else if(b[m][n]==30)
                    b[m][n]=1;
                else
                    b[m][n]=0;
            }
    }
};
