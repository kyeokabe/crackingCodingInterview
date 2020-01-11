class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        map<int,vector<string>> m;
        unordered_set<string> SET;
        SET.insert("");
        string temp="";
        vector<string> foo={""};
        m[0]=foo;
        int MAX_CHAR=INT_MAX;
        help(s,temp,m,SET,MAX_CHAR);
        auto it=m.rbegin();
        return it->second;
    }
    
    bool TooManyClose(string &s){
        int open=0;
        int close=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==')')
                close++;
            if(s[i]=='(')
                open++;
            if(close>open)
                return false;
        }
        return true;
    }
    
    bool isvalid(string &s){
        //cout<<s<<endl;
        int open=0;
        int close=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==')')
                close++;
            if(s[i]=='(')
                open++;
            if(close>open)
                return false;
        }
        return open==close?true:false;
    }
    
    void help(string &s,string &temp,map<int,vector<string>> &m,unordered_set<string> &SET,int &MAX_CHAR){
        if(MAX_CHAR!=INT_MAX&&temp.length()+s.length()<MAX_CHAR)
            return;
        if(TooManyClose(temp)==false)
            return;
        if(s.length()==0){
            if(isvalid(temp)==true&&SET.find(temp)==SET.end()){
                if(MAX_CHAR==INT_MAX)
                    MAX_CHAR=temp.length();
                else if(temp.length()>MAX_CHAR)
                    MAX_CHAR=temp.length();
                if(m.find(temp.length())==m.end()){
                    vector<string> foo={temp};
                    m[temp.length()]=foo;
                }
                else
                    m[temp.length()].push_back(temp);
                SET.insert(temp);
            }
            return;
        }
        /*
        if(s[0]!='('&&s[0]!=')'){
            temp=temp+s[0];
            s=s.substr(1,s.length()-1);
            help(s,temp,m,SET);
            temp=temp.substr(0,temp.length()-1);
        }
        */
        else{
            //add char and backtrack
            temp=temp+s[0];
            s=s.substr(1,s.length()-1);
            help(s,temp,m,SET,MAX_CHAR);
            s=temp[temp.length()-1]+s;
            temp=temp.substr(0,temp.length()-1);
            
            //skip char and backtrack
            string ch=s.substr(0,1);
            s=s.substr(1,s.length()-1);
            help(s,temp,m,SET,MAX_CHAR);
            s=ch+s;
        }
    }  
};
