class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> v(length+1,0);
        
        for(int i=0;i<updates.size();i++){
            v[updates[i][0]]+=updates[i][2];
            v[updates[i][1]+1]-=updates[i][2];
        }
        
        vector<int> ans(length,0);
        int count=v[0];
        ans[0]=v[0];
        for(int i=1;i<v.size()-1;i++){
            count+=v[i];
            ans[i]=count;
        }
        
        return ans;
    }
};
