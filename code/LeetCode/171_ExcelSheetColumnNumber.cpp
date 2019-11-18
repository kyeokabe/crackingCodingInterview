class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        int ptr1=s.length()-1;
        while(ptr1>=0){
            ans+=pow(26,s.length()-1-ptr1)*(s[ptr1]-'A'+1);
            ptr1--;
        }
        return ans;
    }
};
