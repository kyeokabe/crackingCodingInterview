class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size()==0||costs[0].size()==0)
            return 0;
        vector<int> f(3,0);
        vector<vector<int>> v(costs.size(),f);
        v[0][0]=costs[0][0];
        v[0][1]=costs[0][1];
        v[0][2]=costs[0][2];

        for(int i=1;i<costs.size();i++){
            v[i][0]=costs[i][0]+min(v[i-1][1],v[i-1][2]);
            v[i][1]=costs[i][1]+min(v[i-1][2],v[i-1][0]);
            v[i][2]=costs[i][2]+min(v[i-1][0],v[i-1][1]);
        }
        return min(v[costs.size()-1][2],min(v[costs.size()-1][0],v[costs.size()-1][1])); 
    }
};
