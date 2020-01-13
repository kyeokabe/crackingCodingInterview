/*
This solution does not match m[i] to i's top parent.
We don't care about top parent because isolations can be
counted by checking whether m[i]==i or not.


Run another findParent for all i's in order for m[i] to 
represent top parent for i
*/
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
            m[i]=i;
        
        for(int i=0;i<edges.size();i++){
            int root1=findParent(edges[i][0],m);
            int root2=findParent(edges[i][1],m);
            if(root1!=root2){
                m[root1]=root2;
            }
        }
        
        int ans=0;
        auto it=m.begin();
        while(it!=m.end()){
            //cout<<"it->first = "<<it->first<<", it-> second = "<<it->second<<endl;
            if(it->first==it->second)
                ans++;
            it++;
        }
        return ans;
    }
    
    int findParent(int i,unordered_map<int,int> &m){
        while(i!=m[i]){
            m[i]=m[m[i]];
            i=m[i];
        }
        return i;
    }
};
