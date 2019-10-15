class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0)//||obstacleGrid[0].size()==0)
            return 0;
        if(obstacleGrid[0].size()==0)
            return 1;
        if(obstacleGrid[0][0]==1)
            return 0;
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1)
            return 0;
        //it is kind of a cheap shot to have test cases where
        //intermediate combinations overflow ...
        //hence the long data type usage
        vector<long> v2(obstacleGrid[0].size(),-1);
        vector<vector<long>> v;
        for(int i=0;i<obstacleGrid.size();i++)
            v.push_back(v2);
        v[obstacleGrid.size()-1][obstacleGrid[0].size()-1]=1;
        queue<vector<int>> q;
        vector<int> v3;
        v3.push_back(obstacleGrid.size()-1);
        v3.push_back(obstacleGrid[0].size()-1);
        q.push(v3);
        
        while(!q.empty()){
            int r=q.front()[0];
            int c=q.front()[1];
            if(r==0&&c==0)
                return int(v[0][0]);
            
            if(r-1>=0&&v[r-1][c]==-1){
                if(obstacleGrid[r-1][c]==1)
                    v[r-1][c]=0;
                else{
                    int t=(c+1<=obstacleGrid[0].size()-1)?v[r-1][c+1]:0;
                    v[r-1][c]=v[r][c]+t;
                }
                vector<int> temp;
                temp.push_back(r-1);
                temp.push_back(c);
                q.push(temp);
            }
            
            if(c-1>=0&&v[r][c-1]==-1){
                if(obstacleGrid[r][c-1]==1)
                    v[r][c-1]=0;
                else{
                    int t=(r+1<=obstacleGrid.size()-1)?v[r+1][c-1]:0;
                    v[r][c-1]=v[r][c]+t;
                }
                vector<int> temp;
                temp.push_back(r);
                temp.push_back(c-1);
                q.push(temp);
            }
            //if(c<10&&r<10)
            //    cout<<"r = "<<r<<", c = "<<c<<endl;
            q.pop();
        }
        return 0;
    }
};


