class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        string str;
        help(s,ans,v,str);
        return ans;
    }
    
    void help(string s, vector<vector<string>> &ans, vector<string> v, string str){
        if(s.length()==0){
            if(str.length()!=0)
                if(isP(str)){
                    v.push_back(str);
                    ans.push_back(v);
                }
            return;
        }
        
        if(str.length()!=0&&isP(str)){
            vector<string> v2=v;
            v2.push_back(str);
            string str2=s.substr(0,1);
            string s2=s.substr(1,s.length()-1);
            help(s2,ans,v2,str2);
        }
        
        vector<string> v3=v;
        string str3=str+s.substr(0,1);
        string s3=s.substr(1,s.length()-1);
        help(s3,ans,v3,str3);
    }
    
    bool isP(string &s){
        int L=0;
        int R=s.length()-1;
        while(L<R){
            if(s[L]==s[R]){
                L++;
                R--;
            }
            else
                break;
        }
        if(L>=R)
            return true;
        else
            return false;
    }
};
