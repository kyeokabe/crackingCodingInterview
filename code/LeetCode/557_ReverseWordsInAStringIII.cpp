class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ')
                st.push(s[i]);
            else{
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                ans+=' ';
            }
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
