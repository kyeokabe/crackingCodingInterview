class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char,char> m,p;
        for(int i=0;i<s.length();i++){
            auto it=m.find(s[i]);
            if(it==m.end())
                m[s[i]]=t[i];
            else
                if(it->second!=t[i])
                    return false;
        }
        for(int i=0;i<s.length();i++){
            auto it=p.find(t[i]);
            if(it==p.end())
                p[t[i]]=s[i];
            else
                if(it->second!=s[i])
                    return false;
        }
        return true;
    }
};
