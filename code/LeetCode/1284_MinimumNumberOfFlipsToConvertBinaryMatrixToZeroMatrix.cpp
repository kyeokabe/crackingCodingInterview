class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        map<vector<vector<int>>,int> m;
        vector<int> foo(mat[0].size(),0);
        vector<vector<int>> v(mat.size(),foo);
        m[v]++;
        queue<vector<vector<int>>> q;
        int ans=0;
        q.push(v);
        
        while(!q.empty()){
            
            int SIZE=q.size();
            for(int i=0;i<SIZE;i++){
                if(q.front()==mat)
                    return ans;
                
                for(int r=0;r<mat.size();r++){
                    for(int c=0;c<mat[0].size();c++){
                        vector<vector<int>> temp=help(q.front(),r,c);
                        if(temp==mat)
                            return ans+1;
                        else{
                            if(m.find(temp)==m.end()){
                                m[temp]++;
                                q.push(temp);
                            }
                        }
                    }
                }
                q.pop();
            }
            ans++;
        }
        return -1;
    }
    
    vector<vector<int>> help(vector<vector<int>> v, int r, int c){
        v[r][c]=(v[r][c]==0?1:0);
        if(r-1>=0)
            v[r-1][c]=(v[r-1][c]==0?1:0);
        if(c-1>=0)
            v[r][c-1]=(v[r][c-1]==0?1:0);
        if(r+1<v.size())
            v[r+1][c]=(v[r+1][c]==0?1:0);
        if(c+1<v[0].size())
            v[r][c+1]=(v[r][c+1]==0?1:0);
        return v;
    }
    
};
