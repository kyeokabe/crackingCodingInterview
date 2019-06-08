class Solution {
public:
    string strWithout3a3b(int A, int B) {
        bool swapped=false;
        if(A<B){
            swapped=true;
            int C=B;
            B=A;
            A=C;
        }
        string ans="";
        help(A,B,ans);
        string swappedans="";
        for(int i=0;i<ans.length();i++){
            if(ans[i]=='a')
                swappedans+="b";
            else
                swappedans+="a";
        }
        if(swapped)
            return swappedans;
        return ans;
    }
    void help(int A, int B, string &ans){
        if(A==0&&B==0)
            return;
        else if(A==1&&B==0){
            ans+="a";
            return;
        }
        else if(A==2&&B==0){
            ans+="aa";
            return;
        }
        else if(A==1&&B==1){
            ans+="ab";
            return;
        }
        else if(A==2&&B==1){
            ans+="aab";
            return;
        }
        else if(A-2>B){
            ans+="aab";
            help(A-2,B-1,ans);
        }
        else{
            ans+="ab";
            help(A-1,B-1,ans);
        }
    }
};
