class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        bool poss1=possibility2(t,s);
        bool poss2=possibility2(s,t);
        bool poss3=possibility3(s,t);
        return (poss1||poss2||poss3);
    }
    
    bool possibility2(string s, string t){
        
        if(s.length()-1!=t.length())
            return false;        
        int i=0;
        int j=0;
        
        while(j<t.length()&&s[i]==t[j]){
            i++;
            j++;
        }
        
        if(j==t.length())
            return true;
        i++;
        while(i<s.length()&&s[i]==t[j]){
            i++;
            j++;
        }
        if(j!=t.length())
            return false;
        return true;
    }
    
    bool possibility3(string s, string t){
        if(s.length()!=t.length())
            return false;
        int i=0;
        while(i<s.length()&&s[i]==t[i])
            i++;
        if(i==s.length())
            return false;
        i++;
        if(i==s.length())
            return true;
        while(i<s.length()&&s[i]==t[i])
            i++;
        if(i!=s.length())
            return false;
        return true;
    }
    
};
