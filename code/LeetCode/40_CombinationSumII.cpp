class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<vector<int>> ans2;
        for(int i=0;i<candidates.size();i++){
            if(target-candidates[i]>=0){
                vector<int> foo;
                foo.push_back(candidates[i]);
                help(foo,candidates,target-candidates[i],i+1,ans);
            }
        }
        for(int i=0;i<ans.size();i++)
            sort(ans[i].begin(),ans[i].end());
        
        //note that unordered_map gives compile error
        map<vector<int>,int> m;
        
        for(int i=0;i<ans.size();i++){
            auto it=m.find(ans[i]);
            if(it==m.end()){
                m[ans[i]]++;
                ans2.push_back(ans[i]);
            }
        }
        return ans2;
    }
    
    void help(vector<int> foo, vector<int> &candidates, int target, int i, vector<vector<int>> &ans){
        if(target==0)
            ans.push_back(foo);
        else{
            for(int k=i;k<candidates.size();k++){
                if(target-candidates[k]>=0){
                    vector<int> foo2=foo;
                    foo2.push_back(candidates[k]);
                    help(foo2,candidates,target-candidates[k],k+1,ans);
                }
            }        
        }
    }
    
};
