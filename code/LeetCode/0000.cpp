class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        map<vector<int>,int> m;
        
        for(int k=0;k<queens.size();k++)
            m[queens[k]]++;
        
        vector<vector<int>> ans;
        
        for(int k=0;k<queens.size();k++){
            int r=queens[k][0];
            int c=queens[k][1];
            //check left
            while(c-1>=0){
                c--;
                vector<int> foo;
                foo.push_back(r);
                foo.push_back(c);
                auto it=m.find(foo);
                if(it!=m.end())
                    break;
                if(r==king[0]&&c==king[1]){
                    ans.push_back(foo);
                }
            }
            //reset c
            c=queens[k][1];
            
            //check right
            while(c+1<=7){
                c++;
                vector<int> foo;
                foo.push_back(r);
                foo.push_back(c);
                auto it=m.find(foo);
                if(it!=m.end())
                    break;
                if(r==king[0]&&c==king[1]){
                    ans.push_back(foo);
                }
            }
            //reset c
            c=queens[k][1];
            
            //check up
            while(r-1>=0){
                r--;
                vector<int> foo;
                foo.push_back(r);
                foo.push_back(c);
                auto it=m.find(foo);
                if(it!=m.end())
                    break;
                if(r==king[0]&&c==king[1]){
                    ans.push_back(foo);
                }
            }
            //reset r
            r=queens[k][0];
            
            //check down
            while(r+1<=7){
                r++;
                vector<int> foo;
                foo.push_back(r);
                foo.push_back(c);
                auto it=m.find(foo);
                if(it!=m.end())
                    break;
                if(r==king[0]&&c==king[1]){
                    ans.push_back(foo);
                }
            }
            //reset r
            r=queens[k][1];
        }
        return ans;
    }
};
