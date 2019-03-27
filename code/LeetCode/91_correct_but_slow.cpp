class Solution {
public:
    int numDecodings(string s) {
        if (!decodable(s))
            return 0;
        vector<int> foo(s.length()+1,-1);
        return numDecodings2(s,foo);
    }
    
    int numDecodings2(string s, vector<int> &foo){
        if(s[0]-'0'==0)
            return 0;
        
        if (s.length()==0)
            return 1;
        if (s.length()==1)
            return 1;
        if (s.length()==2)
            if((10*(s[0]-'0')+s[1]-'0')>=10 && (10*(s[0]-'0')+(s[1]-'0'))<=26){
                return 1+numDecodings2(s.substr(1,1), foo);
            }
            else
                return 1;
                
        if((10*(s[0]-'0')+s[1]-'0')>=10 && (10*(s[0]-'0')+(s[1]-'0'))<=26){
            return (numDecodings2(s.substr(2,s.length()-1),foo)+numDecodings2(s.substr(1,s.length()-1), foo));
        }
        else
            return numDecodings2(s.substr(1,s.length()-1),foo);
        
    }
    
    bool decodable(string s){
        if (s[0]-'0'==0)
            return false;
        for (int i=1; i<s.length();i++)
            if(s[i]-'0'==0 && s[i-1]-'0'>2)
                return false;
        return true;
    }
};
