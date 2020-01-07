class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<int> temp(bikes.size(),0);
        vector<vector<int>> v(workers.size(),temp);
        vector<list<vector<int>>> distance(2000);
        
        for(int r=0;r<workers.size();r++)
            for(int c=0;c<bikes.size();c++){
                v[r][c]=abs(workers[r][0]-bikes[c][0])+abs(workers[r][1]-bikes[c][1]);
                vector<int> temp2={r,c};
                distance[v[r][c]].push_back(temp2);
            }

        unordered_map<int,int> b;
        unordered_map<int,int> w;
        vector<int> ans(workers.size(),INT_MIN);
        int count=0;
        
        for(int i=0;i<distance.size();i++){
            auto it=distance[i].begin();
            while(it!=distance[i].end()){
                if(w.find((*it)[0])==w.end()&&b.find((*it)[1])==b.end()){
                    ans[(*it)[0]]=(*it)[1];
                    w[(*it)[0]]++;
                    b[(*it)[1]]++;
                    count++;
                }
                if(count==workers.size())
                    break;
                it++;
            }
            if(count==workers.size())
                break;
        }
        
        return ans;
    }
};
