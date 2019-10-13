class Solution {
public:
    int balancedStringSplit(string s) {
        if(s.length()==0)
            return 0;
        int L=0;
        int R=0;
        vector<int> v(s.length(),0);
        if(s[0]=='L')
            L++;
        else
            R++;
        for(int i=1;i<s.length();i++){
            if(s[i]=='L')
                L++;
            if(s[i]=='R')
                R++;
            if(L==R)
                v[i]=v[i-1]+1;
            else
                v[i]=v[i-1];
        }
        return v[s.length()-1];
        
    }
};
