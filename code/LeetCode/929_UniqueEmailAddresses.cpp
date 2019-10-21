class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        unordered_map<string,int> m;
        
        for(int i=0;i<emails.size();i++){
            string s;
            int temp=emails[i].length();
            for(int j=0;j<temp;j++){
                if(emails[i][j]=='@'||emails[i][j]=='+')
                    j=temp;
                else if(emails[i][j]!='.'){
                    s+=emails[i][j];

                }
            }
                int k=0;
                while(emails[i][k]!='@')
                    k++;
                s+=emails[i].substr(k,temp-k);
                m[s]++;            
        }
        
        int ans=0;
        auto it=m.begin();
        while(it!=m.end()){
            ans++;
            it++;
        }
        return ans;
    }
};
