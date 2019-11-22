class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> SET;    
        for(int i=0;i<wordDict.size();i++)
            SET.insert(wordDict[i]);
        
        vector<bool> v(s.length()+1,false);
        v[v.size()-1]=true;
        
        for(int i=v.size()-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                string temp=s.substr(j,i-j+1);
                if(SET.find(temp)!=SET.end()&&v[i+1]==true)
                    v[j]=true;
            }
        }
        return v[0];
    }
};
