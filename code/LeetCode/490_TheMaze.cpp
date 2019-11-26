class Solution {
public:
    bool hasPath(vector<vector<int>>& m, vector<int>& start, vector<int>& goal) {
        int r = start[0];
        int c = start[1];        
        m[r][c]=2;//2 means no walls, but have already visited 
        
        vector<int> v={r,c};
        queue<vector<int>> q;
        q.push(v);
                
        while(!q.empty()){
            int R=q.front()[0];
            int C=q.front()[1];
            r=R;
            c=C;
            //cout<<"R = "<<R<<", C = "<<C<<endl;
            if(R==goal[0]&&C==goal[1])
                return true;

            if(R-1>=0){
                while(R-1>=0&&m[R-1][C]!=1)
                    R--;
                if(R!=r&&m[R][C]!=2){
                    vector<int> temp={R,C};
                    q.push(temp);
                    m[R][C]=2;
                }
            }
        
            R=q.front()[0];
            C=q.front()[1];
            if(R+1<m.size()){
                while(R+1<m.size()&&m[R+1][C]!=1)
                    R++;
                if(R!=r&&m[R][C]!=2){
                    vector<int> temp={R,C};
                    q.push(temp);
                    m[R][C]=2;
                }
            }
        
            R=q.front()[0];
            C=q.front()[1];
            if(C+1<m[0].size()){
                while(C+1<m[0].size()&&m[R][C+1]!=1)
                    C++;
                if(C!=c&&m[R][C]!=2){
                    vector<int> temp={R,C};
                    q.push(temp);
                    m[R][C]=2;
                }
            }
        
            R=q.front()[0];
            C=q.front()[1];
            if(C-1>=0){
                while(C-1>=0&&m[R][C-1]!=1)
                    C--;
                if(C!=c&&m[R][C]!=2){
                    vector<int> temp={R,C};
                    q.push(temp);
                    m[R][C]=2;
                }
            }
            q.pop();
        }
        return false;
    }
};
