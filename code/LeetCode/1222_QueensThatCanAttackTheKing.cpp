class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        map<vector<int>,int> m;
        
        for(int k=0;k<queens.size();k++)
            m[queens[k]]++;
        
        vector<vector<int>> ans;
        
        int r=king[0];
        int c=king[1];
        
        //check left
        while(c-1>=0){
            c--;
            vector<int> foo;
            foo.push_back(r);
            foo.push_back(c);
            auto it=m.find(foo);
            if(it!=m.end()){
                ans.push_back(foo);
                break;
            }
        }
        //reset c
        c=king[1];
        
        //check right
        while(c+1<=7){
            c++;
            vector<int> foo;
            foo.push_back(r);
            foo.push_back(c);
            auto it=m.find(foo);
            if(it!=m.end()){
                ans.push_back(foo);
                break;
            }
        }
        //reset c
        c=king[1];
        
        //check down
        while(r+1<=7){
            r++;
            vector<int> foo;
            foo.push_back(r);
            foo.push_back(c);
            auto it=m.find(foo);
            if(it!=m.end()){
                ans.push_back(foo);
                break;
            }
        }
        //reset r
        r=king[0];
       
        //check up
        while(r-1>=0){
            r--;
            vector<int> foo;
            foo.push_back(r);
            foo.push_back(c);
            auto it=m.find(foo);
            if(it!=m.end()){
                ans.push_back(foo);
                break;
            }
        }
        //reset r
        r=king[0];
        
        //check up left
        while(r-1>=0&&c-1>=0){
            r--;
            c--;
            vector<int> foo;
            foo.push_back(r);
            foo.push_back(c);
            auto it=m.find(foo);
            if(it!=m.end()){
                ans.push_back(foo);
                break;
            }
        }
        //reset r,c
        r=king[0];
        c=king[1];
       
                
        //check up right
        while(r-1>=0&&c+1<=7){
            r--;
            c++;
            vector<int> foo;
            foo.push_back(r);
            foo.push_back(c);
            auto it=m.find(foo);
            if(it!=m.end()){
                ans.push_back(foo);
                break;
            }
        }
        //reset r,c
        r=king[0];
        c=king[1];
     
        //check up right
        while(r+1<=7&&c+1<=7){
            r++;
            c++;
            vector<int> foo;
            foo.push_back(r);
            foo.push_back(c);
            auto it=m.find(foo);
            if(it!=m.end()){
                ans.push_back(foo);
                break;
            }
        }
        //reset r,c
        r=king[0];
        c=king[1];
        
        //check up right
        while(r+1<=7&&c-1>=0){
            r++;
            c--;
            vector<int> foo;
            foo.push_back(r);
            foo.push_back(c);
            auto it=m.find(foo);
            if(it!=m.end()){
                ans.push_back(foo);
                break;
            }
        }
        //reset r,c
        r=king[0];
        c=king[1];
        
        
        return ans;
    }
};
