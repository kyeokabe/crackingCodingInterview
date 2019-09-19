/*
A good way to recognize the pattern is to start from reverse
e.g., make two out of three rows equal and flip cols to see
      what kind of patterns are possible
*/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& m) {
        if(m.size()==1)
            return 1;
        for(int i=0;i<m.size();i++){
            if(m[i][0]!=0)
                for(int j=0;j<m[0].size();j++){
                    if(m[i][j]==0)
                        m[i][j]=1;
                    else
                        m[i][j]=0;
            }
        }
    
        //note that unorderd_map will not work unless
        // > operator is defined for vectors
        map<vector<int>,int> u;
        
        for(int i=0;i<m.size();i++){
            auto it=u.find(m[i]);
            if(it==u.end())
                u[m[i]]++;
            else
                it->second++;
        }
        
        int ans=0;
        
        for(auto it=u.begin();it!=u.end();it++)
            if(it->second>ans)
                ans=it->second;
    
        return ans;
    }
};
