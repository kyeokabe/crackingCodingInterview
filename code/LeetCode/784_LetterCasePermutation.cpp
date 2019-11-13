class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        string foo="";
        ans.push_back(foo);
        
        for(int i=0;i<S.length();i++){
            if(S[i]>='a'&&S[i]<='z'){
                vector<string> temp1=ans;
                for(int j=0;j<ans.size();j++){
                    ans[j]+=S[i];
                    temp1[j]+=(S[i]-32);
                }
                for(int j=0;j<temp1.size();j++)
                    ans.push_back(temp1[j]);
            }
            else if(S[i]>='A'&&S[i]<='Z'){
                vector<string> temp1=ans;
                for(int j=0;j<ans.size();j++){
                    ans[j]+=S[i];
                    temp1[j]+=(S[i]+32);
                }
                for(int j=0;j<temp1.size();j++)
                    ans.push_back(temp1[j]);
            }
            else{
                for(int j=0;j<ans.size();j++)
                    ans[j]+=S[i];
            }
        }
        return ans;
    }
};
