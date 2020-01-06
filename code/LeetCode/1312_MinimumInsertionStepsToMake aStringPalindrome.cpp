class Solution {
public:
    int minInsertions(string s) {
        vector<int> temp(s.length(),INT_MIN);
        vector<vector<int>> v(s.length(),temp);
        
        for(int L=0;L<s.length();L++)
            for(int R=0;R<s.length();R++){
                if(R<L)
                    v[L][R]=0;
                else if(R==L)
                    v[L][R]=1;
            }
        
        int L=0;
        int R=s.length()-1;
        return s.length()-help(s,L,R,v);
    }
    
    int help(string &s,int L,int R, vector<vector<int>> &v){
        if(v[L][R]!=INT_MIN)
            return v[L][R];
        if(s[L]==s[R])
            return 2+((v[L+1][R-1]==INT_MIN)?help(s,L+1,R-1,v):v[L+1][R-1]);
        else{
            int opt1=v[L+1][R]==INT_MIN?help(s,L+1,R,v):v[L+1][R];
            int opt2=v[L][R-1]==INT_MIN?help(s,L,R-1,v):v[L][R-1];
            v[L][R]=max(opt1,opt2);
            return v[L][R];
        }
    }
};
