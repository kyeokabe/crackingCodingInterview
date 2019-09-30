class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        
        for(int i=0;i<c.size();i++){
            vector<int> foo;
            if(t-c[i]>=0){
                foo.push_back(c[i]);
                help(foo,c,t-c[i],ans,i);
            }
        }
        
        return ans;
    }
    
    void help(vector<int> foo, vector<int>& c, int t, vector<vector<int>> &ans,int i){
        if(t==0){
            ans.push_back(foo);
            return;
        }
        for(int k=i;k<c.size();k++){
            if(t-c[k]>=0){
                vector<int> foo2=foo;
                foo2.push_back(c[k]);
                help(foo2,c,t-c[k],ans,k);
            }
        }
    }
    
};
