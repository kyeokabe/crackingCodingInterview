class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)
            return false;
        if(stones.size()==2)
            return true;
        unordered_map<int,int> m;
        map<vector<int>,int> m2;
        for(int i=0;i<stones.size();i++)
            m[stones[i]]++;
        queue<vector<int>> q;
        vector<int> temp={1,1};
        q.push(temp);
        while(!q.empty()){
            if(q.front()[0]+q.front()[1]==stones[stones.size()-1])
                return true;
            if(q.front()[0]+q.front()[1]+1==stones[stones.size()-1])
                return true;
            if(q.front()[1]-1>0)
                if(q.front()[0]+q.front()[1]-1==stones[stones.size()-1])
                    return true;
            
            if(m.find(q.front()[0]+q.front()[1])!=m.end()){
                vector<int> foo={q.front()[0]+q.front()[1],q.front()[1]};
                if(m2.find(foo)==m2.end()){
                    m2[foo]++;
                    q.push(foo);
                }
            }
            if(m.find(q.front()[0]+q.front()[1]+1)!=m.end()){
                vector<int> foo={q.front()[0]+q.front()[1]+1,q.front()[1]+1};
                if(m2.find(foo)==m2.end()){
                    m2[foo]++;
                    q.push(foo);
                }
            }
            if(q.front()[1]-1>0){
                if(m.find(q.front()[0]+q.front()[1]-1)!=m.end()){
                    vector<int> foo={q.front()[0]+q.front()[1]-1,q.front()[1]-1};
                    if(m2.find(foo)==m2.end()){
                        m2[foo]++;
                        q.push(foo);
                    }
                }
            }
            q.pop();
        }
        return false;
    }
};
