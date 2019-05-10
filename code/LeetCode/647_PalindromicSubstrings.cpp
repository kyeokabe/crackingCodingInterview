class Solution {
public:
    int countSubstrings(string s) {
        if(s.length()==0)
            return 0;
        if(s.length()==1)
            return 1;
        int L,R;
        int ans=0;
        for(int i=0;i<s.length();i++){
            L=i;
            R=i;
            while(L>=0&&R<=s.length()-1){
                if(s[L]==s[R]){
                    ++ans;
                    //cout<<"s[L] = "<<s[L]<<", s[R] = "<<s[R]<<", L = "<<L<<", R ="<<R<<endl;
                }
                else
                    break;
                ++R;
                --L;
            }
        }
        
        for(int i=0;i<s.length()-1;i++){
            L=i;
            R=i+1;
            while(L>=0&&R<=s.length()-1){
                if(s[L]==s[R])
                    ++ans;
                else
                    break;
                ++R;
                --L;
            }
        }        
        return ans;
    }
};

/*
asdsa
*/
