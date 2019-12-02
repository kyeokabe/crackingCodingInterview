class Solution {
public:
    int countLetters(string S) {
        if(S.length()==0)
            return 0;
        char ch=S[0];
        int ans=1;
        int temp=1;
        for(int i=1;i<S.length();i++){
            if(S[i]==ch){
                temp++;
                ans+=temp;
            }
            else{
                ch=S[i];
                temp=1;
                ans++;
            }
        }
        return ans;
    }
};
