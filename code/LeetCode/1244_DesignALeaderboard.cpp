class Leaderboard {
private:
    unordered_map<int,int> m;
    vector<unordered_set<int>> v;
    
public:
    Leaderboard() {
        unordered_set<int> s;
        for(int i=0;i<100001;i++)
            v.push_back(s);
        
    }
    
    void addScore(int playerID, int score) {
        auto it=m.find(playerID);
        if(it==m.end()){
            m[playerID]=score;
            v[score].insert(playerID);
        }
        else{
            v[m[playerID]].erase(playerID);
            v[m[playerID]+score].insert(playerID);
            m[playerID]=m[playerID]+score;
        }
    }
    
    int top(int K) {
        int i=100001;
        int sum=0;
        while(K>0&&i>=0){
            if(!v[i].empty()){
                auto it=v[i].begin();
                while(it!=v[i].end()){
                    sum+=i;
                    K--;
                    if(K==0)
                        return sum;
                    else
                        it++;
                }
            }
            i--;
    
            if(K==0)
                return sum;
        }
        return sum;
    }
    
    void reset(int playerID) {
        v[m[playerID]].erase(playerID);
        v[0].insert(playerID);
        m[playerID]=0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
