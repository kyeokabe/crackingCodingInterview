class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> m;
        for(int i=0;i<numCourses;i++){
            vector<int> foo;
            m[i]=foo;
        }
        
        for(int i=0;i<prerequisites.size();i++)
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
             
        unordered_set<int> visited;
        
        while(m.size()!=0){
            auto it=m.begin();
            unordered_set<int> s;
            if(help(s,visited,m,it)==false)
                return false;
            m.erase(it->first);
            it++;
        }
        return true;
    }
    
    bool help(unordered_set<int> &s, unordered_set<int> &visited, unordered_map<int,vector<int>> &m,unordered_map<int,vector<int>>::iterator it){
        if(s.find(it->first)!=s.end())
            return false;
        s.insert(it->first);
        if(visited.find(it->first)!=visited.end())
            return true;
        else{
            visited.insert(it->first);
            while(it->second.size()!=0){
                int temp=it->second[0];
                swap(it->second[0],it->second[it->second.size()-1]);
                it->second.pop_back();
                auto it2=m.find(temp);
                help(s,visited,m,it2);
            }
            return true;
        }
    }  
};
