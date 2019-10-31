class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.length()<10)
            return ans;
        
        unordered_map<string,int> m;
        for(int i=0;i<=s.length()-10;i++){
            string s2=s.substr(i,10);
            m[s2]++;
        }
        
        auto it=m.begin();
        while(it!=m.end()){
            if(it->second>1)
                ans.push_back(it->first);
            it++;
        }
        return ans;
    }
};
