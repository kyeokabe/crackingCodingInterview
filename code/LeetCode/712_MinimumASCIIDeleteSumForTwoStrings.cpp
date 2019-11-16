class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<int> foo(s2.length(),0);
        vector<vector<int>> v(s1.length(),foo);
        
        for(int i=0;i<s1.length();i++){
            for(int j=0;j<s2.length();j++){
                v[i][j]=s1[i]==s2[j]?(2*s1[i]-0):0;
            }
        }
        for(int j=1;j<s2.length();j++)
            v[0][j]=max(v[0][j-1],v[0][j]);
        
        for(int i=1;i<s1.length();i++)
            v[i][0]=max(v[i-1][0],v[i][0]);
        
        for(int i=1;i<s1.length();i++){
            for(int j=1;j<s2.length();j++){
                v[i][j]=max(max(v[i-1][j],v[i][j-1]),v[i-1][j-1]+v[i][j]);
            }
        }
        
        int count=0;
        for(int i=0;i<s1.length();i++)
            count+=(s1[i]-0);
        for(int j=0;j<s2.length();j++)
            count+=(s2[j]-0);
        
        return count-v[s1.length()-1][s2.length()-1];
    }
};
