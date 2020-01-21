class Solution {
public:
    string decodeString(string s) {
        int k=hasB(s);
        if(k!=-1){
            int K=k-1;
            while(K>=0&&s[K]>='0'&&s[K]<='9')
                K--;
            int K2=k;
            while(s[K2]!=']')
                K2++;
            string temp;
            int len=stoi(s.substr(K+1,k-K-1));
            for(int i=0;i<len;i++)
                temp+=s.substr(k+1,K2-(k+1));
            //cout<<temp<<endl;
            string temp2;
            if(K2+1<s.length())
                temp2=s.substr(K2+1,s.length()-(K2));
            s=s.substr(0,K+1)+temp+temp2;
            return decodeString(s);
        }
        else
            return s;
    }
    
    int hasB(string &s){
        int ans=-1;
        for(int i=0;i<s.length();i++)
            if(s[i]=='[')
                ans=i;
        return ans;
    }
};
