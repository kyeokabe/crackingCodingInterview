class Solution {
public:
    bool checkRecord(string s) {
        if(s.length()<=1)
            return true;
        int Acount=0;
        for(int i=0;i<s.length();i++)
            if(s[i]=='A')
                ++Acount;
        if(Acount>=2)
            return false;
        if(s.length()>=3)
            for(int i=0;i<s.length()-2;i++)
                if(s.substr(i,3)=="LLL")//syntax is first char, length
                    return false;
        return true;
    }
};
