class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]]=edges[i][0];
            m[edges[i][1]]=edges[i][1];
        }
        
        for(int i=0;i<edges.size();i++){
            int root1=getParent(edges[i][0],m);
            int root2=getParent(edges[i][1],m);
            
            if(root1!=root2){
                m[root1]=root2;
            }
            else{
                ans=edges[i];
            } 
        }
        return ans;
        
    }
    
    int getParent(int i, unordered_map<int,int> &m){
        while(i!=m[i])
            i=m[i]=m[m[i]];
        return i;
    }
    
};
