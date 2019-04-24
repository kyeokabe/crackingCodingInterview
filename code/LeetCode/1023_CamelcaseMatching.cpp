class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for (int i=0;i<queries.size();i++){
            bool temp=helper(queries[i],pattern);
            ans.push_back(temp);
        }
        return ans;
    }
    
    
    //checks if string s meets problem statement
    bool helper(string s, string pattern){
        if(pattern.length()>s.length())
            return false;
        if(pattern.length()==0)
            return checksmall(s);
        
        if (pattern[0]!=s[0]&&s.length()>=2){
            if (s[0]>=97&&s[0]<=122)
                return helper(s.substr(1,s.length()-1),pattern);
        }
            
        if(pattern[0]==s[0]&&s.length()>=2&&pattern.length()>=2){
            return helper(s.substr(1,s.length()-1),pattern.substr(1,pattern.length()-1));
        }
        
        if(pattern[0]==s[0]&&pattern.length()==1){
            return checksmall(s.substr(1,s.length()-1));
        }
        return false;
    }
    
    //check if all char are small case letters
    bool checksmall(string s){
        for (int i=0;i<s.length();i++)
            if(s[i]<97||s[i]>122)
                return false;
        return true;
    }
    
};
