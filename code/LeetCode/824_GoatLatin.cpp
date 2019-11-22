class Solution {
public:
    string toGoatLatin(string S) {
        
        if(S[0]!=' ')
            S=" "+S;
        if(S[S.length()-1]!=' ')
            S+=" ";
        string ans="";
        string temp="";
        bool isVowel=true;
        string consonant;
        int count=1;
        for(int i=1;i<S.length();i++){
            if(S[i]==' '){
                if(isVowel==false)
                    temp+=consonant;
                temp+="ma";
                for(int i=0;i<count;i++)
                    temp+="a";
                count++;
                temp+=" ";
                ans+=temp;
                temp="";
            }
            else{
                if(S[i-1]==' '){
                    bool cond1=(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u');
                    bool cond2=(S[i]=='A'||S[i]=='E'||S[i]=='I'||S[i]=='O'||S[i]=='U');
                    if(cond1||cond2)
                        isVowel=true;
                    else{
                        isVowel=false;
                        consonant=S[i];
                        continue;
                    }
                }
                temp+=S[i];
            }  
        }
        return ans.substr(0,ans.length()-1);
    }
};
