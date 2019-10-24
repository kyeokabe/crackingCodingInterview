class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char,int> m;
        
        for(int i=0;i<keyboard.size();i++)
            m[keyboard[i]]=i;
        
        int ans=0;
        int last=0;
        
        for(int i=0;i<word.size();i++){
            ans+=abs(m[word[i]]-last);
            last=m[word[i]];
        }
        return ans;
    }
};
