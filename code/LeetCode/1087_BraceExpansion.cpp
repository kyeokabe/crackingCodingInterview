class Solution {
public:
    vector<string> expand(string S) {
        vector<string> ans;
        string foo="";
        ans.push_back(foo);

        for(int i=0;i<S.length();i++){
            if(S[i]=='{'){
                int idx=i+1;
                while(S[idx]!='}')
                    idx++;
                string str=help1(S,i,idx);
                vector<string> temp;
                string foo;
                help(S,str,foo,temp);
                //attach temp to all ans
                vector<string> ans2;
                for(int j=0;j<ans.size();j++){
                    for(int k=0;k<temp.size();k++){
                        ans2.push_back(ans[j]+temp[k]);
                    }
                }
                ans=ans2;
                i=idx;
            }
            else{
                for(int j=0;j<ans.size();j++)
                    ans[j]+=S[i];
            }
        }
        //sort(ans.begin(),ans.end());
        return ans;
    }
   
    string help1(string &S, int ptr1, int ptr2){
        string ans;
        for(int i=ptr1+1;i<ptr2;i++){
            if(S[i]>='a'&&S[i]<='z'||S[i]>='A'&&S[i]<='Z')
                ans+=S[i];
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    void help(string &S, string str, string foo, vector<string> &temp){
        for(int i=0;i<str.length();i++){
            string foo2;
            foo2+=str[i];
            temp.push_back(foo2);
        }
    }

    
    /*
    void help(string &S, string str, string foo, vector<string> &temp){
        if(str.length()==0){
            temp.push_back(foo);
            return;
        }
        else{
            for(int i=0;i<str.length();i++){
                foo+=str[i];
                char temp2=str[i];
                swap(str[i],str[str.length()-1]);
                str=str.substr(0,str.length()-1);
                help(S,str,foo,temp);
                foo=foo.substr(0,foo.length()-1);
                str+=temp2;
                swap(str[i],str[str.length()-1]);
            }
        }
    }
    */
};
