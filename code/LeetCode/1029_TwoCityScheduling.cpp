class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        map<int,int> m;
        vector<vector<int>> v;
        for(int i=0;i<costs.size();i++){
            vector<int> temp={costs[i][1]-costs[i][0],i,costs[i][1],costs[i][0]};
            v.push_back(temp);
        }
            
        sort(v.begin(),v.end());
        
        //m[0] fly to city 1
        //m[2N-1] fly city 0
        int ans=0;
        int count=0;
        for (int i=0;i<costs.size();i++){
            if(count<costs.size()/2)
                ans+=v[i][2];
            else
                ans+=v[i][3];
            ++count;
        }
        return ans;
    }
};
