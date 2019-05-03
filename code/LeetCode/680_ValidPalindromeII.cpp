class Solution {
public:
    bool validPalindrome(string s) {
        if (s.length()<=1)
            return true;
        
        int L=0;
        int R=s.length()-1;
        
        int skip=false;
        
        while(L<R){
            if(s[L]==s[R]){
                ++L;
                --R;
            }
            else if(s[L]!=s[R]){
                if(skip)
                    break;
                skip=true;
                ++L;
            }
            if(L>=R)
                return true;
            
        }

        //reset the initial conditions
        //test for case where R should decrease
        L=0;
        R=s.length()-1;
        skip=false;
        
        while(L<R){
            if(s[L]==s[R]){
                ++L;
                --R;
            }
            else if(s[L]!=s[R]){
                if(skip)
                    return false;
                skip=true;
                --R;
            }
            if(L>=R)
                return true;
        }
        return false;
    }
};
