class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(k>=10)
            return ans;
        
        map<vector<int>,int> m1;
        unordered_map<int,int> m2;
        
        vector<int> v;
        help(v,ans,m1,m2,k,n,1);
        return ans;
    }
    
    void help(vector<int> &v,vector<vector<int>> &ans,map<vector<int>,int> &m1,unordered_map<int,int> &m2,const int k,int n,int s){
        if(n<0)
            return;
        if(v.size()==k&&n==0){
            vector<int> temp=v;
            sort(temp.begin(),temp.end());
            auto it=m1.find(temp);
            if(it==m1.end()){
                m1[v]++;
                ans.push_back(v);
                return;
            }
        }
        
        for(int i=s;i<=9;i++){
            auto it=m2.find(i);
            if(it==m2.end()){
                m2[i]++;
                v.push_back(i);
                help(v,ans,m1,m2,k,n-i,s+1);
                v.pop_back();
                m2.erase(i);
            }   
        }
    }
};
