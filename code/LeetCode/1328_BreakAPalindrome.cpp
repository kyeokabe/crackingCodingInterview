class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.length()==1)
            return "";
        string ans=palindrome;
        int i=0;
        
        while(i<ans.length()&&ans[i]=='a'){
            i++;
        }

        if((ans.length()%2==1)&&(i==ans.length()/2)){
            i++;
            while(i<ans.length()&&ans[i]=='a')
                i++;
        }
        
        if(i==ans.length())
            i--;
        string temp=ans;
        temp[i]='a';
        if(isP(temp)==false)
            return temp;
        temp[i]='b';
        return temp;
    }
    
    bool isP(string s){
        int L=0;
        int R=s.length()-1;
        while(L<R){
            if(s[L]==s[R]){
                L++;
                R--;
            }
            else
                return false;
        }
        return true;
    }
};
