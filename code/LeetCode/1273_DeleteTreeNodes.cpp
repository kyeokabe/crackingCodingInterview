class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        unordered_map<int,vector<int>> m;
        
        if(nodes==1){
            if(value[0]==0)
                return 0;
            return 1;
        }
        
        for(int i=1;i<parent.size();i++){
            if(m.find(parent[i])==m.end()){
                vector<int> temp={i};
                m[parent[i]]=temp;
            }
            else
                m[parent[i]].push_back(i);
        }
        
        queue<int> q;
        q.push(0);
        stack<int> s;
        
        while(!q.empty()){
            
            for(int i=0;i<m[q.front()].size();i++)
                q.push(m[q.front()][i]);
            
            s.push(q.front());
            q.pop();
        }

        while(s.size()!=1){
            value[parent[s.top()]]+=value[s.top()];
            s.pop();
        }

        if(value[0]==0)
            return 0;
        
        q.push(0);
        int ans=1;
        

        while(!q.empty()){
            for(int i=0;i<m[q.front()].size();i++){
                if(value[m[q.front()][i]]!=0){
                    q.push(m[q.front()][i]);
                    ans++;
                }
            }
            q.pop();
        }
        return ans;
    }
};
