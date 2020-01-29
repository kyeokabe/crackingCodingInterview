class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int,string>> st;
        int i=0;
        while(i<s.length()){
            if(st.empty()){
                pair<int,string> p={1,s.substr(i,1)};
                if(p.first!=k)
                    st.push(p);
            }
            else if(st.top().second==s.substr(i,1)){
                pair<int,string> p=st.top();
                p.first=p.first+1;
                st.pop();
                if(p.first!=k)
                    st.push(p);
            }
            else{
                pair<int,string> p={1,s.substr(i,1)};
                if(p.first!=k)
                    st.push(p);
            }
            i++;
        }
        
        string ans;
        
        while(!st.empty()){
            string temp;
            for(int i=0;i<st.top().first;i++)
                temp+=st.top().second;
            ans=temp+ans;
            st.pop();
        }
        
        return ans;
    }
};
