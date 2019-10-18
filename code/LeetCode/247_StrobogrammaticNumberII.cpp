class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> v;
        string s;
        
        vector<string> v1={"0","0"};
        vector<string> v2={"1","1"};
        vector<string> v3={"8","8"};
        vector<string> v4={"6","9"};
        vector<string> v5={"9","6"};
        
        vector<vector<string>> x;
        x.push_back(v1);
        x.push_back(v2);
        x.push_back(v3);
        x.push_back(v4);
        x.push_back(v5);
        
        if(n%2==1){
            vector<string> mid={"0","1","8"};
            for(int i=0;i<mid.size();i++){
                s+=mid[i];
                help(s,n-1,v,x);
                s="";
            }
        }
        else{
            help(s,n,v,x);
        }
        return v;
    }
    
    void help(string s,int n, vector<string> &v, vector<vector<string>> &x){
        if(n==0){
            //check if '010', '0690', '080' etc
            if(badzero(s)==false)
                v.push_back(s);
        }
        else{
            for(int i=0;i<x.size();i++){
                s=x[i][0]+s+x[i][1];
                help(s,n-2,v,x);
                s=s.substr(1,s.length()-2);
            }
        }
    }
    
    bool badzero(string s){
        if(s.length()>=2)
            if(s[0]=='0'&&s[s.length()-1]=='0')
                return true;
        return false;
    }
    
};
