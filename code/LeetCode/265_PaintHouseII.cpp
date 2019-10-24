class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size()==0||costs[0].size()==0)
            return 0;
        vector<int> f(costs[0].size(),0);
        vector<vector<int>> v(costs.size(),f);
        
        for(int i=0;i<costs[0].size();i++)
            v[0][i]=costs[0][i];

        for(int i=1;i<costs.size();i++){
            for(int j=0;j<costs[0].size();j++){
                int temp=INT_MAX;
                for(int m=0;m<costs[0].size();m++){
                    if(m!=j)
                        temp=min(temp,v[i-1][m]);
                }
                v[i][j]=costs[i][j]+temp;
            }
        }
        
        int ans=INT_MAX;
        for(int i=0;i<costs[0].size();i++)
            ans=min(ans,v[costs.size()-1][i]);
        
        return ans; 
    }
};
