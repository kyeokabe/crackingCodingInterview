class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0)
            return 0;
        if(needle.length()>haystack.length())
            return -1;
        for(int i=0;i<=haystack.length()-needle.length();i++)
            for(int j=i;j<i+needle.length();j++){
                if(haystack[j]!=needle[j-i])
                    break;
                else
                    if(j==i+needle.length()-1)
                        return i;
            }
        return -1;
    }
};
