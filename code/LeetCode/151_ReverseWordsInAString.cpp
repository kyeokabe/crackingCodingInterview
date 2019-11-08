class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(temp.length()>0)
                    st.push(temp);
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        if(temp.length()>0)
            st.push(temp);
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            ans+=" ";
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};
