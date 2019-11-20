class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                auto it=m.find(i);
                if(it==m.end()){
                    vector<int> temp;
                    m[i]=temp;
                }
                m[i].push_back(graph[i][j]);
            }
        }
        int N=graph.size()-1;
        vector<vector<int>> ans;
        vector<int> temp={0};
        help(ans,m,temp,N);
        return ans;
    }
    
    void help(vector<vector<int>> &ans,unordered_map<int,vector<int>> &m,vector<int> temp,int N){
        if(temp[temp.size()-1]==N){
            ans.push_back(temp);
            return;
        }
        auto it=m.find(temp[temp.size()-1]);
        if(it==m.end())
            return;
        else{
            auto it2=it->second.begin();
            while(it2!=it->second.end()){
                temp.push_back(*it2);
                help(ans,m,temp,N);
                temp.pop_back();
                it2++;
            }
        }
    }
};
