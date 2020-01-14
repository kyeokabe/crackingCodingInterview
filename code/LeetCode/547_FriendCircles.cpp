class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        unordered_map<int,int> m;
        for(int i=0;i<M.size();i++)
            m[i]=i;
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M.size();j++){
                if(i!=j&&M[i][j]==1){
                    int root1=getParent(i,m);
                    int root2=getParent(j,m);
                    if(root1!=root2){
                        m[root1]=root2;
                    }
                }
            }
        }
        int ans=0;
        auto it=m.begin();
        while(it!=m.end()){
            if(it->first==it->second)
                ans++;
            it++;
        }
        return ans;
    }
    
    int getParent(int i, unordered_map<int,int> &m){
        while(i!=m[i])
            i=m[i]=m[m[i]];
        return i;
    }
};
