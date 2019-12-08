class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> m;
        
        for(int i=0;i<groupSizes.size();i++){
            auto it=m.find(groupSizes[i]);
            if(it==m.end()){
                vector<int> temp={i};
                m[groupSizes[i]]=temp;
            }
            else{
                m[groupSizes[i]].push_back(i);
            }
        }
        vector<vector<int>> v;
        auto it=m.begin();
        while(it!=m.end()){
            if(it->first==it->second.size()){
                v.push_back(it->second);
            }
            else{
                while(it->second.size()!=0){
                    vector<int> temp;
                    for(int i=0;i<it->first;i++){
                        temp.push_back(it->second.back());
                        it->second.pop_back();
                    }
                    v.push_back(temp);
                }
            }
            it++;
        }
        return v;
    }
};
