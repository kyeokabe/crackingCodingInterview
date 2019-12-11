class Solution {
public:
    void reverseWords(vector<char>& s) {
        int L=0;
        int R=s.size()-1;
        
        while(R>L){
            swap(s[L],s[R]);
            R--;
            L++;
        }
        
        L=0;
        R=0;
        while(R<s.size()){
            while(R<s.size()&&s[R]!=' ')
                R++;
            int l=L;
            int r=R-1;
            while(r>l){
                swap(s[r],s[l]);
                r--;
                l++;
            }
            while(R<s.size()&&s[R]==' ')
                R++;
            L=R;
        }
        return;
    }
};
