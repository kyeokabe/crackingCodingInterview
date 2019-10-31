class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> v1(26,0);
        
        for(int i=0;i<A[0].size();i++)
            v1[A[0][i]-97]++;
        if(A.size()>1){
            for(int i=1;i<A.size();i++){
                vector<int> v2(26,0);
                for(int j=0;j<A[i].size();j++)
                    v2[A[i][j]-97]++;   
                for(int k=0;k<26;k++){
                    v1[k]=min(v1[k],v2[k]);
                }
            }                   
        }
        
        vector<string> ans;
        for(int i=0;i<26;i++){
            while(v1[i]>0){
                string foo(1,char(i+97));
                ans.push_back(foo);
                v1[i]--;
            }
        }
        return ans;
    }
};
