class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.length()==0)
            return 0;
        vector<int> temp(s.length(),INT_MIN);
        vector<vector<int>> v(s.length(),temp);
        
        for(int i=0;i<s.length();i++)
            v[i][i]=1;
        
        int R=s.length()-1;
        int L=0;
        
        return help(v,R,L,s);        
    }
    
    int help(vector<vector<int>> &v,int R, int L, string &s){
        if(v[L][R]!=INT_MIN)
            return v[L][R];
        if(R<L)
            return 0;
        if(s[R]==s[L]){
            v[L][R]=2+help(v,R-1,L+1,s);
        }
        else{
            int opt1=(v[L+1][R]==INT_MIN)?help(v,R,L+1,s):v[L+1][R];
            int opt2=(v[L][R-1]==INT_MIN)?help(v,R-1,L,s):v[L][R-1];
            v[L][R]=max(opt1,opt2);
        }
        return v[L][R];
    }
};
