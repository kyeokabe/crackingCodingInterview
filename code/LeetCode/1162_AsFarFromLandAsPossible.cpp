class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        //map<vector<int>,int> m;
        queue<vector<int>> q;
        for(int r=0;r<grid.size();r++)
            for(int c=0;c<grid[0].size();c++)
                if(grid[r][c]==1){
                    vector<int> temp={r,c};
                    q.push(temp);
                }
        
        if(q.size()==0||q.size()==grid.size()*grid[0].size())
            return -1;
        
        int ans=-1;
        
        while(!q.empty()){
            queue<vector<int>> q2;
            //cout<<"q size = "<<q.size()<<endl;
            while(!q.empty()){
                int R=q.front()[0];
                int C=q.front()[1];
                
                if(R-1>=0&&grid[R-1][C]==0){
                    vector<int> temp={R-1,C};
                    q2.push(temp);
                }
                if(C-1>=0&&grid[R][C-1]==0){
                    vector<int> temp={R,C-1};
                    q2.push(temp);
                }
                if(R+1<grid.size()&&grid[R+1][C]==0){
                    vector<int> temp={R+1,C};
                    q2.push(temp);
                }
                if(C+1<grid.size()&&grid[R][C+1]==0){
                    vector<int> temp={R,C+1};
                    q2.push(temp);
                }
                q.pop();
            }
            //cout<<"after pop size = "<<q.size()<<endl;
            while(!q2.empty()){
                if(grid[q2.front()[0]][q2.front()[1]]==0){
                    q.push(q2.front());
                    grid[q2.front()[0]][q2.front()[1]]=1;
                }
                q2.pop();
            }
            ans++;
        }
        
        return ans;
    }
};
