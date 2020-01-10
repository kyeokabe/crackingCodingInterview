class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set<string> SET;
        
        for(int i=0;i<wordDict.size();i++)
            SET.insert(wordDict[i]);
        
        vector<int> v(s.length()+1,false);
        v.back()=true;
        for(int i=v.size()-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(v[i+1]==true){
                    if(SET.find(s.substr(j,i-j+1))!=SET.end())
                        v[j]=true;
                }
            }
        }
        if(v[0]==false)
            return ans;

        string temp="";
        help(ans,SET,s,temp);        
        for(int i=0;i<ans.size();i++)
            ans[i]=ans[i].substr(0,ans[i].length()-1);
        
        return ans;
    }
    
    void help(vector<string> &ans,unordered_set<string> &SET,string &s,string &temp){
        
        if(s.length()==0){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<s.length();i++){
            string temp2=s.substr(0,i+1);
            s=s.substr(i+1,s.length()-(i+1));
            
            if(SET.find(temp2)!=SET.end()){
                temp=temp+temp2+" ";
                
                help(ans,SET,s,temp);
                
                temp=temp.substr(0,temp.length()-temp2.length()-1);
            }
            s=temp2+s;
        }
        return;
    }
};
