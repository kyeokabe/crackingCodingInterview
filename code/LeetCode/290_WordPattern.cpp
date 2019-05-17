class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> foo;
        string temp="";
        for(int i=0;i<str.length();i++){
            if(str[i]!=' '){
                temp+=str[i];
                if (i==str.length()-1)
                    foo.push_back(temp);
            }
            else
            {
                if(temp.length()>=1)
                    foo.push_back(temp);
                temp="";
            }
        }
        if(pattern.length()!=foo.size())
            return false;
        unordered_map<char,string> m;
        unordered_map<string,string> m2;
        int j=0;
        for(int i=0;i<pattern.size();i++){
            auto it=m.find(pattern[i]);
            if(it!=m.end()){
                if(it->second!=foo[j])
                    return false;
            }
            else
            {
                auto it2=m2.find(foo[j]);
                if(it2!=m2.end())
                    return false;
            }
            m2[foo[j]]=foo[j];
            m[pattern[i]]=foo[j];
            ++j;
        }
        return true;
    }
};
