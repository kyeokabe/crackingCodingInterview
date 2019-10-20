class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f) {
        unordered_map<string,int> m;
        for(int i=0;i<f.size();i++){
            auto it=m.find(f[i]);
            if(it==m.end()){
                m[f[i]]++;
            }
            it=m.find(f[i]);
            
            string temp=f[i];
            
            while(temp.length()>1){
                temp.pop_back();
                if(temp.length()>1&&temp[temp.length()-1]=='/'){
                    temp.pop_back();
                    auto it2=m.find(temp);
                    if(it2!=m.end()){
                        m.erase(it->first);
                        it=it2;
                    }
                }
            }  
        }
        
        for(int i=0;i<f.size();i++){
            auto it=m.find(f[i]);
            if(it==m.end()){
                m[f[i]]++;
            }
            it=m.find(f[i]);
            
            string temp=f[i];
            
            while(temp.length()>1){
                temp.pop_back();
                if(temp.length()>1&&temp[temp.length()-1]=='/'){
                    temp.pop_back();
                    auto it2=m.find(temp);
                    if(it2!=m.end()){
                        m.erase(it->first);
                        it=it2;
                    }
                }
            }  
        }
        
        vector<string> ans;
        
        auto it=m.begin();
        while(it!=m.end()){
            ans.push_back(it->first);
            it++;
        }
        
        return ans;
    }
};
