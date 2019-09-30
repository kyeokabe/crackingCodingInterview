class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        unordered_map<int,int> m2;
        
        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;
        
        auto it=m.begin();
        while(it!=m.end()){
            auto it2=m2.find(it->second);
            if(it2!=m2.end())
                return false;
            else
                m2[it->second]++;
            it++;
        }
        
        return true;
    }
};
