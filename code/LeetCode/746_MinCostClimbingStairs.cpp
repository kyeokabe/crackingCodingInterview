class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> v(cost.size(),0);
        //v[i] ... cost to arrive at i
        
        
        for(int i=2;i<v.size();i++)
            v[i]=min(v[i-2]+cost[i-2],v[i-1]+cost[i-1]);
        
        //the last two elements of v + cost to move up are candidates for answer
        return min(v[v.size()-1]+cost[v.size()-1],v[v.size()-2]+cost[v.size()-2]);
    }
};
