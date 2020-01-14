class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
            m[i]=i;
        for(int i=0;i<connections.size();i++){
            int root1=getParent(connections[i][0],m);
            int root2=getParent(connections[i][1],m);
            if(root1!=root2){
                m[root1]=root2;
            }
        }
        
        auto it=m.begin();
        int island=0;
        while(it!=m.end()){
            if(it->first==it->second)
                island++;
            it++;
        }
        return island-1;
    }
    
    int getParent(int i, unordered_map<int,int> &m){
        while(i!=m[i])
            i=m[i]=m[m[i]];//compression
        return i;
    }
};
