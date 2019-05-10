class Solution {
public:
    string longestPalindrome(string s) {
        int L;
        int R;
        int ans=0;
        string ans2="";
        int temp;
        for(int i=0;i<s.length();i++){
            L=i;
            R=i;
            temp=-1;
            while(L>=0&&R<=s.length()-1){
                if(s[L]==s[R]){
                    temp+=2;
                    if(ans<temp){
                        ans=temp;
                        ans2="";
                        for(int k=L;k<=R;k++)
                            ans2+=s[k];
                    }
                    --L;
                    ++R;
                }
                else
                    break;
            }
        }
 
        for(int i=0;i<s.length();i++){
            L=i;
            R=i+1;
            temp=0;
            while(L>=0&&R<=s.length()-1){
                if(s[L]==s[R]){
                    temp+=2;
                    if(ans<temp){
                        ans=temp;
                        ans2="";
                        for(int k=L;k<=R;k++)
                            ans2+=s[k];
                    }
                    --L;
                    ++R;
                }
                else
                    break;
            }
        }
        return ans2;
    }
};
