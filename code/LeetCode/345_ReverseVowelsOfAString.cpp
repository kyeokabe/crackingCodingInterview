class Solution {
public:
    string reverseVowels(string s) {
        int L=0;
        int R=s.length()-1;
        while(L<R){
            while(L<R&&s[L]!='a'&&s[L]!='e'&&s[L]!='i'&&s[L]!='o'&&s[L]!='u'&&s[L]!='A'&&s[L]!='E'&&s[L]!='I'&&s[L]!='O'&&s[L]!='U')
                L++;
            while(L<R&&s[R]!='a'&&s[R]!='e'&&s[R]!='i'&&s[R]!='o'&&s[R]!='u'&&s[R]!='A'&&s[R]!='E'&&s[R]!='I'&&s[R]!='O'&&s[R]!='U')
                R--;
            if(L>=R)
                break;
            char foo=s[R];
            s[R]=s[L];
            s[L]=foo;
            L++;
            R--;
        }
        return s;
    }
};
