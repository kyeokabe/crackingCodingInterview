class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length()==0)
            return 0;
        int i=s.length()-1;
        while(i>=0&&s[i]==' ')
            i--;
        int j=i;
        if(i==-1)
            return 0;
        i--;
        while(i>=0&&s[i]!=' ')
            i--;
        return j-i;
    }
};
