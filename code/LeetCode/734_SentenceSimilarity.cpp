class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        
        if(words1.size()!=words2.size())
            return false;
        unordered_map<string,set<string>> m;
        
        for(int i=0;i<pairs.size();i++){
            auto it=m.find(pairs[i][0]);
            if(it==m.end()){
                set<string> s={pairs[i][0],pairs[i][1]};
                m[pairs[i][0]]=s;
            }
            else
                it->second.insert(pairs[i][1]);
            
            auto it2=m.find(pairs[i][1]);
            if(it2==m.end()){
                set<string> s={pairs[i][1],pairs[i][0]};
                m[pairs[i][1]]=s;
            }
            else
                it2->second.insert(pairs[i][0]);
        }
        
        for(int i=0;i<words1.size();i++){
            if(words1[i]==words2[i])
                continue;
            else{
                auto it=m.find(words1[i]);
                if(it==m.end())
                    return false;
                else{
                    auto it2=it->second.find(words2[i]);
                    if(it2!=it->second.end())
                        continue;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};
